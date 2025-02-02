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

#ifndef CONNECTION_OBJECT_MOCK_H_
#define CONNECTION_OBJECT_MOCK_H_

#include <gmock/gmock.h>

#include "conn/abstract_connection_object.h"

class ConnectionObjectMock : public supla_abstract_connection_object {
 public:
  explicit ConnectionObjectMock(supla_connection *connection);
  virtual supla_abstract_srpc_call_handler_collection *
  get_srpc_call_handler_collection(void);
  void set_id(int id);
  void set_guid(const char guid[SUPLA_GUID_SIZE]);
  void set_authkey(const char authkey[SUPLA_AUTHKEY_SIZE]);
  virtual bool is_sleeping_object(void);
  virtual unsigned int get_time_to_wakeup_msec(void);
};

#endif /* CONNECTION_OBJECT_MOCK_H_ */
