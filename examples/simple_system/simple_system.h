/*******************************************************************************
 * Copyright 2017 eyck@minres.com
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations under
 * the License.
 ******************************************************************************/
/*
 * simplesystem.h
 *
 *  Created on: 17.09.2017
 *      Author: eyck@minres.com
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
