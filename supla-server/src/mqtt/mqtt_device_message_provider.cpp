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

#include <mqtt_device_message_provider.h>

supla_mqtt_device_message_provider::supla_mqtt_device_message_provider(void)
    : supla_mqtt_message_provider() {
  row = NULL;
}

/*
typedef struct {
  int device_mfr_id;
  char device_name[SUPLA_DEVICE_NAME_MAXSIZE];
  int device_proto_version;
  char device_softver[SUPLA_SOFTVER_MAXSIZE];
} _mqtt_db_data_row_device_t;
 * */

supla_mqtt_device_message_provider::~supla_mqtt_device_message_provider(void) {}

void supla_mqtt_device_message_provider::get_mfr_name(int mfr_id, char *buf,
                                                      size_t buf_size) {
  switch (mfr_id) {
    case SUPLA_MFR_ACSOFTWARE:
      snprintf(buf, buf_size, "AC SOFTWARE");
      break;
    case SUPLA_MFR_TRANSCOM:
      snprintf(buf, buf_size, "TransCom");
      break;
    case SUPLA_MFR_LOGI:
      snprintf(buf, buf_size, "Logi");
      break;
    case SUPLA_MFR_ZAMEL:
      snprintf(buf, buf_size, "Zamel");
      break;
    case SUPLA_MFR_NICE:
      snprintf(buf, buf_size, "Nice");
      break;
    case SUPLA_MFR_ITEAD:
      snprintf(buf, buf_size, "Itead");
      break;
    case SUPLA_MFR_DOYLETRATT:
      snprintf(buf, buf_size, "Doyle & Tratt");
      break;
    case SUPLA_MFR_HEATPOL:
      snprintf(buf, buf_size, "Heatpol");
      break;
    case SUPLA_MFR_FAKRO:
      snprintf(buf, buf_size, "Fakro");
      break;
    case SUPLA_MFR_PEVEKO:
      snprintf(buf, buf_size, "Peveko");
      break;
    case SUPLA_MFR_WEKTA:
      snprintf(buf, buf_size, "Wekta");
      break;
    case SUPLA_MFR_STA_SYSTEM:
      snprintf(buf, buf_size, "STA-System");
      break;
    default:
      buf[0] = 0;
      break;
  }
}

bool supla_mqtt_device_message_provider::get_message_at_index(
    unsigned short index, const char *topic_prefix, char **topic_name,
    void **message, size_t *message_size) {
  if (row != NULL) {
    switch (index) {
      case 0:
        return create_message(topic_prefix, row->user_email, topic_name,
                              message, message_size,
                              row->device_enabled ? "true" : "false", false,
                              "/devices/%i/enabled", row->device_id);
      case 1:
        return create_message(topic_prefix, row->user_email, topic_name,
                              message, message_size, row->device_location,
                              false, "/devices/%i/location");
      case 2:
        return create_message(topic_prefix, row->user_email, topic_name,
                              message, message_size, row->device_last_connected,
                              false, "/devices/%i/last_connected");
      case 3:
        return create_message(topic_prefix, row->user_email, topic_name,
                              message, message_size, row->device_last_ipv4,
                              false, "/devices/%i/last_ipv4");
      case 4: {
        char mfr_name[20];
        get_mfr_name(row->device_mfr_id, mfr_name, sizeof(mfr_name));
        return create_message(topic_prefix, row->user_email, topic_name,
                              message, message_size, mfr_name, false,
                              "/devices/%i/manufacturer");
      }

      case 5:
        return create_message(topic_prefix, row->user_email, topic_name,
                              message, message_size, row->device_name, false,
                              "/devices/%i/name");
      case 6: {
        char proto_ver[15];
        snprintf(proto_ver, sizeof(proto_ver), "%i", row->device_proto_version);

        return create_message(topic_prefix, row->user_email, topic_name,
                              message, message_size, proto_ver, false,
                              "/devices/%i/proto_ver");
      }
      case 7:
        return create_message(topic_prefix, row->user_email, topic_name,
                              message, message_size, row->device_softver, false,
                              "/devices/%i/soft_ver");
    }
  }

  return false;
}

void supla_mqtt_device_message_provider::set_data_row(
    _mqtt_db_data_row_device_t *row) {
  this->row = row;
  set_message_count(8);
}
