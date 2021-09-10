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

#include "actiontriggerconfig.h"

#include <ctype.h>
#include <string.h>

#include "proto.h"

#define MAX_STR_LEN 20

action_trigger_config::action_trigger_config(void) : channel_json_config() {}

action_trigger_config::action_trigger_config(channel_json_config *root)
    : channel_json_config(root) {}

bool action_trigger_config::equal_to_string(cJSON *item, const char *str) {
  if (!item || !str) {
    return false;
  }

  char *istr = cJSON_GetStringValue(item);

  if (!istr) {
    return false;
  }

  size_t str_len = strnlen(str, MAX_STR_LEN);

  if (str_len != strnlen(istr, MAX_STR_LEN)) {
    return false;
  }

  for (size_t a = 0; a < str_len; a++) {
    if (tolower(str[a]) != tolower(istr[a])) {
      return false;
    }
  }

  return true;
}

unsigned int action_trigger_config::get_capabilities(void) {
  unsigned int result = 0;
  cJSON *json = get_json_root();
  if (!json) {
    return result;
  }

  cJSON *st = cJSON_GetObjectItem(json, "supportedTriggers");
  if (!st || !cJSON_IsArray(st)) {
    return result;
  }

  int st_size = cJSON_GetArraySize(st);

  for (short a = 0; a < st_size; a++) {
    cJSON *item = cJSON_GetArrayItem(st, a);
    if (equal_to_string(item, "TURN_ON")) {
      result |= SUPLA_ACTION_CAP_TURN_ON;
    } else if (equal_to_string(item, "TURN_OFF")) {
      result |= SUPLA_ACTION_CAP_TURN_OFF;
    } else if (equal_to_string(item, "TOGGLE_X1")) {
      result |= SUPLA_ACTION_CAP_TOGGLE_x1;
    } else if (equal_to_string(item, "TOGGLE_X2")) {
      result |= SUPLA_ACTION_CAP_TOGGLE_x2;
    } else if (equal_to_string(item, "TOGGLE_X3")) {
      result |= SUPLA_ACTION_CAP_TOGGLE_x3;
    } else if (equal_to_string(item, "TOGGLE_X4")) {
      result |= SUPLA_ACTION_CAP_TOGGLE_x4;
    } else if (equal_to_string(item, "TOGGLE_X5")) {
      result |= SUPLA_ACTION_CAP_TOGGLE_x5;
    } else if (equal_to_string(item, "HOLD")) {
      result |= SUPLA_ACTION_CAP_HOLD;
    } else if (equal_to_string(item, "SHORT_PRESS_X1")) {
      result |= SUPLA_ACTION_CAP_SHORT_PRESS_x1;
    } else if (equal_to_string(item, "SHORT_PRESS_X2")) {
      result |= SUPLA_ACTION_CAP_SHORT_PRESS_x2;
    } else if (equal_to_string(item, "SHORT_PRESS_X3")) {
      result |= SUPLA_ACTION_CAP_SHORT_PRESS_x3;
    } else if (equal_to_string(item, "SHORT_PRESS_X4")) {
      result |= SUPLA_ACTION_CAP_SHORT_PRESS_x4;
    } else if (equal_to_string(item, "SHORT_PRESS_X5")) {
      result |= SUPLA_ACTION_CAP_SHORT_PRESS_x5;
    }
  }

  return result;
}

bool action_trigger_config::set_capabilities(unsigned int caps) {
  unsigned int all_possible =
      SUPLA_ACTION_CAP_TURN_ON | SUPLA_ACTION_CAP_TURN_OFF |
      SUPLA_ACTION_CAP_TOGGLE_x1 | SUPLA_ACTION_CAP_TOGGLE_x2 |
      SUPLA_ACTION_CAP_TOGGLE_x3 | SUPLA_ACTION_CAP_TOGGLE_x4 |
      SUPLA_ACTION_CAP_TOGGLE_x5 | SUPLA_ACTION_CAP_HOLD |
      SUPLA_ACTION_CAP_SHORT_PRESS_x1 | SUPLA_ACTION_CAP_SHORT_PRESS_x2 |
      SUPLA_ACTION_CAP_SHORT_PRESS_x3 | SUPLA_ACTION_CAP_SHORT_PRESS_x4 |
      SUPLA_ACTION_CAP_SHORT_PRESS_x5;

  caps = all_possible & caps;

  if (caps == get_capabilities()) {
    return false;
  }

  return false;
}
