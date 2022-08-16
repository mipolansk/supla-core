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

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <stddef.h>
#include <sys/time.h>

#include <memory>

#include "eh.h"
#include "srpc/srpc.h"

#define LOCAL_IPV4_ARRAY_SIZE 5

class supla_connection_object;
class supla_device;
class supla_client;
class supla_connection {
 private:
  static void *reg_pending_arr;
  static struct timeval reg_limit_exceeded_alert_time;
  static struct timeval reg_limit_exceeded_time;
  static unsigned int local_ipv4[LOCAL_IPV4_ARRAY_SIZE];
  static bool reject_all_new_connections;

  static void read_local_ipv4_addresses(void);
  void set_registered(char registered);
  void on_device_reconnect_request(
      void *_srpc, TCS_DeviceReconnectRequest *cs_device_reconnect_request);
  void on_set_channel_function_request(
      TCS_SetChannelFunction *cs_set_channel_function);
  void on_set_caption_request(TCS_SetCaption *cs_set_caption, bool channel);
  void on_register_device_request(void *_srpc, unsigned int call_type,
                                  unsigned char proto_version,
                                  TsrpcReceivedData *rd);
  void trim_caption_to100chars(char *Caption,
                               unsigned _supla_int_t *CaptionSize);

 protected:
  unsigned int client_ipv4;
  void *ssd;
  void *supla_socket;
  void *_srpc;
  void *sthread;
  TEventHandler *eh;

  struct timeval init_time;
  unsigned char activity_timeout;

  std::shared_ptr<supla_connection_object> object;
  std::shared_ptr<supla_client> get_client(void);  // tmp
  std::shared_ptr<supla_device> get_device(void);  // tmp

  char registered;

  int incorrect_call_counter;
  void catch_incorrect_call(unsigned int call_type);

 public:
  std::shared_ptr<supla_connection_object> get_object(void);
  static void log_limits(void);
  static bool is_connection_allowed(unsigned int ipv4);
  static bool conn_limit_exceeded_soft(void);
  static bool conn_limit_exceeded_hard(void);

  supla_connection(void *ssd, void *supla_socket, unsigned int client_ipv4);
  static void init(void);
  static void cleanup(void);
  static int registration_pending_count();
  void execute(void *sthread);
  void terminate(void);
  virtual ~supla_connection();

  int socket_read(void *buf, size_t count);
  int socket_write(const void *buf, size_t count);
  void on_remote_call_received(void *_srpc, unsigned int rr_id,
                               unsigned int call_type,
                               unsigned char proto_version);
  void *srpc(void);
  unsigned int get_client_ipv4(void);
  int get_client_sd(void);
  unsigned char get_activity_timeout(void);
  unsigned char get_protocol_version(void);
};

#endif /* CONNECTION_H_ */
