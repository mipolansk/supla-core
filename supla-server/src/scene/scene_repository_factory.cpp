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

#include "scene/scene_repository_factory.h"

#include "scene/scene_repository.h"

supla_scene_repository_factory::supla_scene_repository_factory(int user_id)
    : supla_dobject_repository_factory(user_id) {}

supla_scene_repository_factory::~supla_scene_repository_factory() {}

supla_dobject_repository* supla_scene_repository_factory::get_repository(void) {
  return new supla_scene_repository(get_user_id());
}
