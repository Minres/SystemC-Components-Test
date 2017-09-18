/*
 * test_initiator.cpp
 *
 *  Created on: 17.09.2017
 *      Author: ubuntu
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
    gp.set_address(0);
    gp.set_data_ptr(data.data());
    gp.set_data_length(data.size());
    sc_core::sc_time delay;
    intor->b_transport(gp, delay);
    wait(10, sc_core::SC_NS);
}

} /* namespace sysc */
