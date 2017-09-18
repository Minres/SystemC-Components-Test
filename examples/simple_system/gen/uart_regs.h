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

#ifndef _UART_REGS_H_
#define _UART_REGS_H_

#include <util/bit_field.h>
#include <sysc/register.h>
#include <sysc/tlmtarget.h>
#include <sysc/utilities.h>

namespace sysc {

template<unsigned BUSWIDTH=32>
class uart_regs :
        public sc_core::sc_module,
        public sysc::tlm_target<BUSWIDTH>,
        public sysc::resetable
 {
protected:
    // storage declarations
    BEGIN_BF_DECL(txdata_t, uint32_t);
        BF_FIELD(data, 0, 8);
        BF_FIELD(full, 31, 1);
    END_BF_DECL() r_txdata;
    
    BEGIN_BF_DECL(rxdata_t, uint32_t);
        BF_FIELD(data, 0, 8);
        BF_FIELD(empty, 31, 1);
    END_BF_DECL() r_rxdata;
    
    BEGIN_BF_DECL(txctrl_t, uint32_t);
        BF_FIELD(txen, 0, 1);
        BF_FIELD(nstop, 1, 1);
        BF_FIELD(reserved, 2, 14);
        BF_FIELD(txcnt, 16, 3);
    END_BF_DECL() r_txctrl;
    
    BEGIN_BF_DECL(rxctrl_t, uint32_t);
        BF_FIELD(rxen, 0, 1);
        BF_FIELD(reserved, 1, 15);
        BF_FIELD(rxcnt, 16, 3);
    END_BF_DECL() r_rxctrl;
    
    BEGIN_BF_DECL(ie_t, uint32_t);
        BF_FIELD(txwm, 0, 1);
        BF_FIELD(rxwm, 1, 1);
    END_BF_DECL() r_ie;
    
    BEGIN_BF_DECL(ip_t, uint32_t);
        BF_FIELD(txwm, 0, 1);
        BF_FIELD(rxwm, 1, 1);
    END_BF_DECL() r_ip;
    
    BEGIN_BF_DECL(div_t, uint32_t);
        BF_FIELD(div, 0, 16);
    END_BF_DECL() r_div;
    
    // register declarations
    sysc::sc_register<typename txdata_t::StorageType> txdata;
    sysc::sc_register<typename rxdata_t::StorageType> rxdata;
    sysc::sc_register<typename txctrl_t::StorageType> txctrl;
    sysc::sc_register<typename rxctrl_t::StorageType> rxctrl;
    sysc::sc_register<typename ie_t::StorageType> ie;
    sysc::sc_register<typename ip_t::StorageType> ip;
    sysc::sc_register<typename div_t::StorageType> div;
    
    uart_regs(sc_core::sc_module_name nm);
protected:
    sc_core::sc_time clk;
};
//////////////////////////////////////////////////////////////////////////////
// member functions
//////////////////////////////////////////////////////////////////////////////

template<unsigned BUSWIDTH>
uart_regs<BUSWIDTH>::uart_regs(sc_core::sc_module_name nm)
: sc_core::sc_module(nm)
, sysc::tlm_target<BUSWIDTH>(clk)
, NAMED(txdata, r_txdata, 0, *this)
, NAMED(rxdata, r_rxdata, 0, *this)
, NAMED(txctrl, r_txctrl, 0, *this)
, NAMED(rxctrl, r_rxctrl, 0, *this)
, NAMED(ie, r_ie, 0, *this)
, NAMED(ip, r_ip, 0, *this)
, NAMED(div, r_div, 0, *this)
{
    this->socket_map.addEntry(&txdata, 0x0UL, 0x4UL);
    this->socket_map.addEntry(&rxdata, 0x4UL, 0x4UL);
    this->socket_map.addEntry(&txctrl, 0x8UL, 0x4UL);
    this->socket_map.addEntry(&rxctrl, 0xcUL, 0x4UL);
    this->socket_map.addEntry(&ie, 0x10UL, 0x4UL);
    this->socket_map.addEntry(&ip, 0x14UL, 0x4UL);
    this->socket_map.addEntry(&div, 0x18UL, 0x4UL);
}
 
}
#endif // _UART_REGS_H_
