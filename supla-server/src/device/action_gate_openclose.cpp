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

#include "action_gate_openclose.h"
#include <assert.h>
#include "action_gate_openclose_search_condition.h"
#include "asynctask/asynctask_queue.h"

supla_action_gate_openclose::supla_action_gate_openclose(
    supla_asynctask_queue *queue, supla_abstract_asynctask_thread_pool *pool,
    supla_abstract_action_executor *action_executor,
    supla_abstract_gate_state_getter *state_getter, int user_id, int device_id,
    int channel_id, unsigned int verification_delay_us, bool open)
    : supla_abstract_asynctask(queue, pool) {
  action_init(action_executor, state_getter, user_id, device_id, channel_id,
              verification_delay_us, open);
}

supla_action_gate_openclose::supla_action_gate_openclose(
    supla_asynctask_queue *queue, supla_abstract_asynctask_thread_pool *pool,
    short priority, bool release_immediately,
    supla_abstract_action_executor *action_executor,
    supla_abstract_gate_state_getter *state_getter, int user_id, int device_id,
    int channel_id, unsigned int verification_delay_us, bool open)
    : supla_abstract_asynctask(queue, pool, priority, release_immediately) {
  action_init(action_executor, state_getter, user_id, device_id, channel_id,
              verification_delay_us, open);
}

void supla_action_gate_openclose::action_init(
    supla_abstract_action_executor *action_executor,
    supla_abstract_gate_state_getter *state_getter, int user_id, int device_id,
    int channel_id, unsigned int verification_delay_us, bool open) {
  assert(action_executor);
  this->action_executor = action_executor;
  this->user_id = user_id;
  this->device_id = device_id;
  this->channel_id = channel_id;
  this->open = open;
  this->attempt_count_left = 4;
  this->state_getter = state_getter;
  this->verification_delay_us = verification_delay_us;

  action_executor->set_channel_id(user_id, device_id, channel_id);
  set_waiting();
}

int supla_action_gate_openclose::get_user_id(void) { return user_id; }

int supla_action_gate_openclose::get_device_id(void) { return device_id; }

int supla_action_gate_openclose::get_channel_id(void) { return channel_id; }

bool supla_action_gate_openclose::_execute(bool *execute_again) {
  bool is_closed = open;
  attempt_count_left--;

  if (!state_getter->get_related_openingsensor_state(
          get_user_id(), get_device_id(), get_channel_id(), &is_closed)) {
    return false;
  }

  if (attempt_count_left < 0 || open != is_closed) {
    return open != is_closed;
  }

  action_executor->open_close();
  *execute_again = true;
  set_delay_usec(verification_delay_us);

  return false;
}

void supla_action_gate_openclose::task_will_added(void) {
  supla_action_gate_openclose_search_condition cnd(
      get_user_id(), get_device_id(), get_channel_id());
  get_queue()->cancel_task(&cnd);
}
