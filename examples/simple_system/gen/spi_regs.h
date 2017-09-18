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

#ifndef _SPI_REGS_H_
#define _SPI_REGS_H_

#include <util/bit_field.h>
#include <sysc/register.h>
#include <sysc/tlmtarget.h>
#include <sysc/utilities.h>

namespace sysc {

template<unsigned BUSWIDTH=32>
class spi_regs :
        public sc_core::sc_module,
        public sysc::tlm_target<BUSWIDTH>,
        public sysc::resetable
 {
protected:
    // storage declarations
    BEGIN_BF_DECL(sckdiv_t, uint32_t);
        BF_FIELD(div, 0, 12);
    END_BF_DECL() r_sckdiv;
    
    BEGIN_BF_DECL(sckmode_t, uint32_t);
        BF_FIELD(pha, 0, 1);
        BF_FIELD(pol, 1, 1);
    END_BF_DECL() r_sckmode;
    
    uint32_t r_csid;
    
    uint32_t r_csdef;
    
    BEGIN_BF_DECL(csmode_t, uint32_t);
        BF_FIELD(mode, 0, 2);
    END_BF_DECL() r_csmode;
    
    BEGIN_BF_DECL(delay0_t, uint32_t);
        BF_FIELD(cssck, 0, 8);
        BF_FIELD(sckcs, 16, 8);
    END_BF_DECL() r_delay0;
    
    BEGIN_BF_DECL(delay1_t, uint32_t);
        BF_FIELD(intercs, 0, 16);
        BF_FIELD(interxfr, 16, 8);
    END_BF_DECL() r_delay1;
    
    BEGIN_BF_DECL(fmt_t, uint32_t);
        BF_FIELD(proto, 0, 2);
        BF_FIELD(endian, 2, 1);
        BF_FIELD(dir, 3, 1);
        BF_FIELD(len, 16, 4);
    END_BF_DECL() r_fmt;
    
    BEGIN_BF_DECL(txdata_t, uint32_t);
        BF_FIELD(data, 0, 8);
        BF_FIELD(full, 31, 1);
    END_BF_DECL() r_txdata;
    
    BEGIN_BF_DECL(rxdata_t, uint32_t);
        BF_FIELD(data, 0, 8);
        BF_FIELD(empty, 31, 1);
    END_BF_DECL() r_rxdata;
    
    BEGIN_BF_DECL(txmark_t, uint32_t);
        BF_FIELD(txmark, 0, 3);
    END_BF_DECL() r_txmark;
    
    BEGIN_BF_DECL(rxmark_t, uint32_t);
        BF_FIELD(rxmark, 0, 3);
    END_BF_DECL() r_rxmark;
    
    BEGIN_BF_DECL(fctrl_t, uint32_t);
        BF_FIELD(en, 0, 1);
    END_BF_DECL() r_fctrl;
    
    BEGIN_BF_DECL(ffmt_t, uint32_t);
        BF_FIELD(cmd_en, 0, 1);
        BF_FIELD(addr_len, 1, 2);
        BF_FIELD(pad_cnt, 3, 4);
        BF_FIELD(cmd_proto, 7, 2);
        BF_FIELD(addr_proto, 9, 2);
        BF_FIELD(data_proto, 11, 2);
        BF_FIELD(cmd_code, 16, 8);
        BF_FIELD(pad_code, 24, 8);
    END_BF_DECL() r_ffmt;
    
    BEGIN_BF_DECL(ie_t, uint32_t);
        BF_FIELD(txwm, 0, 1);
        BF_FIELD(rxwm, 1, 1);
    END_BF_DECL() r_ie;
    
    BEGIN_BF_DECL(ip_t, uint32_t);
        BF_FIELD(txwm, 0, 1);
        BF_FIELD(rxwm, 1, 1);
    END_BF_DECL() r_ip;
    
    // register declarations
    sysc::sc_register<typename sckdiv_t::StorageType> sckdiv;
    sysc::sc_register<typename sckmode_t::StorageType> sckmode;
    sysc::sc_register<uint32_t> csid;
    sysc::sc_register<uint32_t> csdef;
    sysc::sc_register<typename csmode_t::StorageType> csmode;
    sysc::sc_register<typename delay0_t::StorageType> delay0;
    sysc::sc_register<typename delay1_t::StorageType> delay1;
    sysc::sc_register<typename fmt_t::StorageType> fmt;
    sysc::sc_register<typename txdata_t::StorageType> txdata;
    sysc::sc_register<typename rxdata_t::StorageType> rxdata;
    sysc::sc_register<typename txmark_t::StorageType> txmark;
    sysc::sc_register<typename rxmark_t::StorageType> rxmark;
    sysc::sc_register<typename fctrl_t::StorageType> fctrl;
    sysc::sc_register<typename ffmt_t::StorageType> ffmt;
    sysc::sc_register<typename ie_t::StorageType> ie;
    sysc::sc_register<typename ip_t::StorageType> ip;
    
    spi_regs(sc_core::sc_module_name nm);
protected:
    sc_core::sc_time clk;
};
//////////////////////////////////////////////////////////////////////////////
// member functions
//////////////////////////////////////////////////////////////////////////////

template<unsigned BUSWIDTH>
spi_regs<BUSWIDTH>::spi_regs(sc_core::sc_module_name nm)
: sc_core::sc_module(nm)
, sysc::tlm_target<BUSWIDTH>(clk)
, NAMED(sckdiv, r_sckdiv, 0, *this)
, NAMED(sckmode, r_sckmode, 0, *this)
, NAMED(csid, r_csid, 0, *this)
, NAMED(csdef, r_csdef, 0, *this)
, NAMED(csmode, r_csmode, 0, *this)
, NAMED(delay0, r_delay0, 0, *this)
, NAMED(delay1, r_delay1, 0, *this)
, NAMED(fmt, r_fmt, 0, *this)
, NAMED(txdata, r_txdata, 0, *this)
, NAMED(rxdata, r_rxdata, 0, *this)
, NAMED(txmark, r_txmark, 0, *this)
, NAMED(rxmark, r_rxmark, 0, *this)
, NAMED(fctrl, r_fctrl, 0, *this)
, NAMED(ffmt, r_ffmt, 0, *this)
, NAMED(ie, r_ie, 0, *this)
, NAMED(ip, r_ip, 0, *this)
{
    this->socket_map.addEntry(&sckdiv, 0x0UL, 0x4UL);
    this->socket_map.addEntry(&sckmode, 0x4UL, 0x4UL);
    this->socket_map.addEntry(&csid, 0x10UL, 0x4UL);
    this->socket_map.addEntry(&csdef, 0x14UL, 0x4UL);
    this->socket_map.addEntry(&csmode, 0x18UL, 0x4UL);
    this->socket_map.addEntry(&delay0, 0x28UL, 0x4UL);
    this->socket_map.addEntry(&delay1, 0x2cUL, 0x4UL);
    this->socket_map.addEntry(&fmt, 0x40UL, 0x4UL);
    this->socket_map.addEntry(&txdata, 0x48UL, 0x4UL);
    this->socket_map.addEntry(&rxdata, 0x4cUL, 0x4UL);
    this->socket_map.addEntry(&txmark, 0x50UL, 0x4UL);
    this->socket_map.addEntry(&rxmark, 0x54UL, 0x4UL);
    this->socket_map.addEntry(&fctrl, 0x60UL, 0x4UL);
    this->socket_map.addEntry(&ffmt, 0x64UL, 0x4UL);
    this->socket_map.addEntry(&ie, 0x70UL, 0x4UL);
    this->socket_map.addEntry(&ip, 0x74UL, 0x4UL);
}
 
}
#endif // _SPI_REGS_H_
