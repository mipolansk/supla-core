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

#ifndef SUPLA_ABSTRACT_SCENE_DAO_H_
#define SUPLA_ABSTRACT_SCENE_DAO_H_

#include "active_period.h"

class supla_abstract_scene_dao {
 private:
 public:
  supla_abstract_scene_dao();
  virtual ~supla_abstract_scene_dao();

  virtual unsigned int get_estimated_execution_time_and_active_period(
      int scene_id, supla_active_period *active_period) = 0;
};

#endif /*SUPLA_ABSTRACT_SCENE_DAO_H_ */
