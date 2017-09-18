////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 eyck@minres.com
// 
// Licensed under the Apache License, Version 2.0 (the "License"); you may not
// use this file except in compliance with the License.  You may obtain a copy
// of the License at
// 
//   http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
// License for the specific language governing permissions and limitations under
// the License.
////////////////////////////////////////////////////////////////////////////////
/*
 * test_initiator.cpp
 *
 *  Created on: 17.09.2017
 *      Author: eyck@minres.com
 */

#include "test_initiator.h"
#include <sysc/utilities.h>
#include <array>

namespace sysc {

test_initiator::test_initiator(sc_core::sc_module_name nm)
: sc_core::sc_module(nm)
, NAMED(intor)
{
    SC_THREAD(run);

}

void test_initiator::run() {
    wait(10, sc_core::SC_NS);
    tlm::tlm_generic_payload gp;
    std::array<uint8_t, 4> data;
    gp.set_command(tlm::TLM_READ_COMMAND);
    gp.set_address(0x10012000);
    gp.set_data_ptr(data.data());
    gp.set_data_length(data.size());
    gp.set_streaming_width(4);
    sc_core::sc_time delay;
    intor->b_transport(gp, delay);
    wait(10, sc_core::SC_NS);
}

} /* namespace sysc */
