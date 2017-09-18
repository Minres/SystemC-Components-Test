/*
 * test_initiator.h
 *
 *  Created on: 17.09.2017
 *      Author: ubuntu
 */

#ifndef SIMPLE_SYSTEM_TEST_INITIATOR_H_
#define SIMPLE_SYSTEM_TEST_INITIATOR_H_

#include <tlm_utils/simple_initiator_socket.h>
#include <systemc>

namespace sysc {

class test_initiator: public sc_core::sc_module {
public:
    SC_HAS_PROCESS(test_initiator);
    tlm_utils::simple_initiator_socket<test_initiator, 32> intor;

    test_initiator(sc_core::sc_module_name nm);
protected:
    void run();
};

} /* namespace sysc */

#endif /* SIMPLE_SYSTEM_TEST_INITIATOR_H_ */
