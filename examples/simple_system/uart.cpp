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

#include "uart.h"

namespace sysc {

uart::uart(sc_core::sc_module_name nm)
: uart_regs<>(nm)
, NAMED(clk_i)
{
    SC_METHOD(clock_cb);
    sensitive<<clk_i;
}

uart::~uart() {
}

void uart::clock_cb() {
    this->clk=clk_i.read();
}

} /* namespace sysc */
