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

#ifndef _GPIO_REGS_H_
#define _GPIO_REGS_H_

#include <util/bit_field.h>
#include <sysc/register.h>
#include <sysc/utilities.h>
#include <sysc/tlm_target.h>

namespace sysc {

class gpio_regs :
        public sc_core::sc_module,
        public sysc::resetable
{
public:
    // storage declarations
    uint32_t r_value;
    
    uint32_t r_input_en;
    
    uint32_t r_output_en;
    
    uint32_t r_port;
    
    uint32_t r_pue;
    
    uint32_t r_ds;
    
    uint32_t r_rise_ie;
    
    uint32_t r_rise_ip;
    
    uint32_t r_fall_ie;
    
    uint32_t r_fall_ip;
    
    uint32_t r_high_ie;
    
    uint32_t r_high_ip;
    
    uint32_t r_low_ie;
    
    uint32_t r_low_ip;
    
    uint32_t r_iof_en;
    
    uint32_t r_iof_sel;
    
    uint32_t r_out_xor;
    
    // register declarations
    sysc::sc_register<uint32_t> value;
    sysc::sc_register<uint32_t> input_en;
    sysc::sc_register<uint32_t> output_en;
    sysc::sc_register<uint32_t> port;
    sysc::sc_register<uint32_t> pue;
    sysc::sc_register<uint32_t> ds;
    sysc::sc_register<uint32_t> rise_ie;
    sysc::sc_register<uint32_t> rise_ip;
    sysc::sc_register<uint32_t> fall_ie;
    sysc::sc_register<uint32_t> fall_ip;
    sysc::sc_register<uint32_t> high_ie;
    sysc::sc_register<uint32_t> high_ip;
    sysc::sc_register<uint32_t> low_ie;
    sysc::sc_register<uint32_t> low_ip;
    sysc::sc_register<uint32_t> iof_en;
    sysc::sc_register<uint32_t> iof_sel;
    sysc::sc_register<uint32_t> out_xor;
    
    gpio_regs(sc_core::sc_module_name nm);

    template<unsigned BUSWIDTH=32>
    void registerResources(sysc::tlm_target<BUSWIDTH>& target);

};
}

//////////////////////////////////////////////////////////////////////////////
// member functions
//////////////////////////////////////////////////////////////////////////////

inline sysc::gpio_regs::gpio_regs(sc_core::sc_module_name nm)
: sc_core::sc_module(nm)
, NAMED(value, r_value, 0, *this)
, NAMED(input_en, r_input_en, 0, *this)
, NAMED(output_en, r_output_en, 0, *this)
, NAMED(port, r_port, 0, *this)
, NAMED(pue, r_pue, 0, *this)
, NAMED(ds, r_ds, 0, *this)
, NAMED(rise_ie, r_rise_ie, 0, *this)
, NAMED(rise_ip, r_rise_ip, 0, *this)
, NAMED(fall_ie, r_fall_ie, 0, *this)
, NAMED(fall_ip, r_fall_ip, 0, *this)
, NAMED(high_ie, r_high_ie, 0, *this)
, NAMED(high_ip, r_high_ip, 0, *this)
, NAMED(low_ie, r_low_ie, 0, *this)
, NAMED(low_ip, r_low_ip, 0, *this)
, NAMED(iof_en, r_iof_en, 0, *this)
, NAMED(iof_sel, r_iof_sel, 0, *this)
, NAMED(out_xor, r_out_xor, 0, *this)
{
}

template<unsigned BUSWIDTH>
inline void sysc::gpio_regs::registerResources(sysc::tlm_target<BUSWIDTH>& target) {
    target.addResource(value, 0x0UL, 0x4UL);
    target.addResource(input_en, 0x4UL, 0x4UL);
    target.addResource(output_en, 0x8UL, 0x4UL);
    target.addResource(port, 0xcUL, 0x4UL);
    target.addResource(pue, 0x10UL, 0x4UL);
    target.addResource(ds, 0x14UL, 0x4UL);
    target.addResource(rise_ie, 0x18UL, 0x4UL);
    target.addResource(rise_ip, 0x1cUL, 0x4UL);
    target.addResource(fall_ie, 0x20UL, 0x4UL);
    target.addResource(fall_ip, 0x24UL, 0x4UL);
    target.addResource(high_ie, 0x28UL, 0x4UL);
    target.addResource(high_ip, 0x2cUL, 0x4UL);
    target.addResource(low_ie, 0x30UL, 0x4UL);
    target.addResource(low_ip, 0x34UL, 0x4UL);
    target.addResource(iof_en, 0x38UL, 0x4UL);
    target.addResource(iof_sel, 0x3cUL, 0x4UL);
    target.addResource(out_xor, 0x40UL, 0x4UL);
}

#endif // _GPIO_REGS_H_
