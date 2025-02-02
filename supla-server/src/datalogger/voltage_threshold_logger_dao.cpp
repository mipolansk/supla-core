/*
 Copyright (C) AC SOFTWARE SP. Z O.O.

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include "datalogger/voltage_threshold_logger_dao.h"

#include <string.h>

#include "log.h"

supla_voltage_threshold_logger_dao::supla_voltage_threshold_logger_dao(
    supla_abstract_db_access_provider *dba) {
  this->dba = dba;
}

bool supla_voltage_threshold_logger_dao::get_utc_timestamp(MYSQL_TIME *time) {
  MYSQL_STMT *stmt = NULL;

  bool result = false;

  if (dba->stmt_execute((void **)&stmt, "SELECT UTC_TIMESTAMP()", nullptr, 0,
                        true)) {
    MYSQL_BIND rbind = {};

    rbind.buffer_type = MYSQL_TYPE_DATETIME;
    rbind.buffer = time;
    rbind.buffer_length = sizeof(MYSQL_TIME);

    if (mysql_stmt_bind_result(stmt, &rbind)) {
      supla_log(LOG_ERR, "MySQL - stmt bind error - %s",
                mysql_stmt_error(stmt));
    } else {
      mysql_stmt_store_result(stmt);

      if (mysql_stmt_num_rows(stmt) > 0 && !mysql_stmt_fetch(stmt)) {
        result = true;
      }
    }

    mysql_stmt_close(stmt);
  }

  return result;
}

void supla_voltage_threshold_logger_dao::add(MYSQL_TIME *time, int channel_id,
                                             char phase,
                                             supla_voltage_analyzer *va) {
  if (!va || (va->get_below_count() == 0 && va->get_above_count() == 0)) {
    return;
  }

  MYSQL_BIND pbind[15] = {};

  int count_total = va->get_sample_count();
  int count_above = va->get_above_count();
  int count_below = va->get_below_count();
  int sec_total = va->get_total_time_msec() / 1000;
  int sec_above = va->get_total_msec_above() / 1000;
  int sec_below = va->get_total_msec_below() / 1000;
  int max_sec_above = va->get_max_msec_above() / 1000;
  int max_sec_below = va->get_max_msec_below() / 1000;

  char min_voltage[10] = {};
  snprintf(min_voltage, sizeof(min_voltage), "%07.2f", va->get_min());

  char max_voltage[10] = {};
  snprintf(max_voltage, sizeof(max_voltage), "%07.2f", va->get_max());

  char avg_voltage[10] = {};
  snprintf(avg_voltage, sizeof(avg_voltage), "%07.2f", va->get_avg());

  int measurement_time_sec = va->get_total_time_msec() / 1000;

  pbind[0].buffer_type = MYSQL_TYPE_DATETIME;
  pbind[0].buffer = (char *)time;

  pbind[1].buffer_type = MYSQL_TYPE_LONG;
  pbind[1].buffer = (char *)&channel_id;

  pbind[2].buffer_type = MYSQL_TYPE_TINY;
  pbind[2].buffer = (char *)&phase;

  pbind[3].buffer_type = MYSQL_TYPE_LONG;
  pbind[3].buffer = (char *)&count_total;

  pbind[4].buffer_type = MYSQL_TYPE_LONG;
  pbind[4].buffer = (char *)&count_above;

  pbind[5].buffer_type = MYSQL_TYPE_LONG;
  pbind[5].buffer = (char *)&count_below;

  pbind[6].buffer_type = MYSQL_TYPE_LONG;
  pbind[6].buffer = (char *)&sec_total;

  pbind[7].buffer_type = MYSQL_TYPE_LONG;
  pbind[7].buffer = (char *)&sec_above;

  pbind[8].buffer_type = MYSQL_TYPE_LONG;
  pbind[8].buffer = (char *)&sec_below;

  pbind[9].buffer_type = MYSQL_TYPE_LONG;
  pbind[9].buffer = (char *)&max_sec_above;

  pbind[10].buffer_type = MYSQL_TYPE_LONG;
  pbind[10].buffer = (char *)&max_sec_below;

  pbind[11].buffer_type = MYSQL_TYPE_DECIMAL;
  pbind[11].buffer = min_voltage;
  pbind[11].buffer_length = strnlen(min_voltage, sizeof(min_voltage));

  pbind[12].buffer_type = MYSQL_TYPE_DECIMAL;
  pbind[12].buffer = max_voltage;
  pbind[12].buffer_length = strnlen(max_voltage, sizeof(max_voltage));

  pbind[13].buffer_type = MYSQL_TYPE_DECIMAL;
  pbind[13].buffer = avg_voltage;
  pbind[13].buffer_length = strnlen(avg_voltage, sizeof(avg_voltage));

  pbind[14].buffer_type = MYSQL_TYPE_LONG;
  pbind[14].buffer = (char *)&measurement_time_sec;

  const char sql[] =
      "CALL `supla_add_em_voltage_log_item`(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";

  MYSQL_STMT *stmt = nullptr;
  dba->stmt_execute((void **)&stmt, sql, pbind, 15, true);

  if (stmt != nullptr) mysql_stmt_close(stmt);
}

void supla_voltage_threshold_logger_dao::add(supla_voltage_analyzers *vas) {
  if (!vas) {
    return;
  }

  MYSQL_TIME time = {};

  if (get_utc_timestamp(&time)) {
    add(&time, vas->get_channel_id(), 1, vas->get_phase1());
    add(&time, vas->get_channel_id(), 2, vas->get_phase2());
    add(&time, vas->get_channel_id(), 3, vas->get_phase3());
  }
}
