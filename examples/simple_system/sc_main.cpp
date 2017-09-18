////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 ubuntu
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
 * sc_main.cpp
 *
 *  Created on: 17.09.2017
 *      Author: ubuntu
 */

#include "simple_system.h"
#include <sysc/tracer.h>
#include "sysc/scv_tr_db.h"
#include <boost/program_options.hpp>

using namespace sysc;
namespace po = boost::program_options;

namespace {
const size_t ERROR_IN_COMMAND_LINE = 1;
const size_t SUCCESS = 0;
const size_t ERROR_UNHANDLED_EXCEPTION = 2;
} // namespace

int sc_main(int argc, char* argv[]){
    ///////////////////////////////////////////////////////////////////////////
    // CLI argument parsing
    ///////////////////////////////////////////////////////////////////////////
    po::options_description desc("Options");\
    desc.add_options()\
        ("help,h", "Print help message")\
        ("debug,d", po::value<int>(), "set debug level")\
        ("trace,t", "trace SystemC signals");
    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm); // can throw
        // --help option
        if ( vm.count("help")  ){
            std::cout << "JIT-ISS simulator for AVR" << std::endl << desc << std::endl;
            return SUCCESS;
        }
        po::notify(vm); // throws on error, so do after help in case
        // there are any problems
    } catch(po::error& e){
        std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
        std::cerr << desc << std::endl;
        return ERROR_IN_COMMAND_LINE;
    }
    ///////////////////////////////////////////////////////////////////////////
    // set up tracing & transaction recording
    ///////////////////////////////////////////////////////////////////////////
    sysc::tracer trace("simple_system", sysc::tracer::TEXT, vm.count("trace"));
    ///////////////////////////////////////////////////////////////////////////
    // initialize VCD tracer
    ///////////////////////////////////////////////////////////////////////////
    sc_trace_file* tf = sc_create_vcd_trace_file("my_db");

    simple_system i_simple_system("i_simple_system");

    sc_start(sc_core::sc_time(100, sc_core::SC_NS));

    return 0;
}

