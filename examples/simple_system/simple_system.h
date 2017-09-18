/*
 * simplesystem.h
 *
 *  Created on: 17.09.2017
 *      Author: ubuntu
 */

#ifndef SIMPLESYSTEM_H_
#define SIMPLESYSTEM_H_

#include "uart.h"
#include "spi.h"
#include "gpio.h"

#include "test_initiator.h"
#include <sysc/router.h>
#include <sysc/kernel/sc_module.h>
#include <array>


namespace sysc {

class simple_system: public sc_core::sc_module {
public:
    test_initiator i_master;
    router<> i_router;
    uart i_uart;
    spi i_spi;
    gpio i_gpio;
    sc_core::sc_signal<sc_core::sc_time> s_clk;

    simple_system(sc_core::sc_module_name nm);
    virtual ~simple_system();

#include "gen/e300_plat_t.h"
};

} /* namespace sysc */

#endif /* SIMPLESYSTEM_H_ */
