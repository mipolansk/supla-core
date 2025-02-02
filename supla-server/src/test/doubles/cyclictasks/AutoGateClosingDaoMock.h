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

#ifndef AUTO_GATE_CLOSING_DAO_MOCK_H_
#define AUTO_GATE_CLOSING_DAO_MOCK_H_

#include <gmock/gmock.h>

#include "cyclictasks/abstract_auto_gate_closing_dao.h"

namespace testing {

class AutoGateClosingDaoMock : public supla_abstract_auto_gate_closing_dao {
 public:
  explicit AutoGateClosingDaoMock(supla_abstract_db_access_provider *dba);
  virtual ~AutoGateClosingDaoMock(void);
  MOCK_METHOD0(get_all_active, std::vector<item_t>(void));
  MOCK_METHOD1(mark_gate_open, int(int channel_id));
  MOCK_METHOD1(mark_gate_closed, void(int channel_id));
  MOCK_METHOD1(set_closing_attempt, void(int channel_id));
};

} /* namespace testing */

#endif /* AUTO_GATE_CLOSING_DAO_MOCK_H_ */
