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

#ifndef USER_CLIENTCONTAINER_H_
#define USER_CLIENTCONTAINER_H_

#include <list>
#include <memory>

#include "channel_address.h"
#include "client.h"
#include "conn/connection_objects.h"

class supla_user_client_container : public supla_connection_objects {
 public:
  supla_user_client_container();
  virtual ~supla_user_client_container();

  bool add(std::shared_ptr<supla_client> client);

  std::shared_ptr<supla_client> find_by_id(int client_id);
  std::shared_ptr<supla_client> find_by_guid(const char *guid);
  void set_channel_function(int channel_id, int func);
  bool get_client_name(int client_id, char *buffer, int size);
  bool is_super_user_authorized(int client_id);
  void update_device_channels(int location_id, int device_id);
  void on_channel_value_changed(std::list<channel_address> addr_list,
                                bool extended);
  void call_event(TSC_SuplaEvent *event);
  void on_device_calcfg_result(int channel_id, TDS_DeviceCalCfgResult *result);
  void on_device_channel_state_result(int channel_id, TDSC_ChannelState *state);
  void set_channel_caption(int channel_id, char *caption);
  void set_location_caption(int location_id, char *caption);
};

#endif /* USER_CLIENTCONTAINER_H_ */
