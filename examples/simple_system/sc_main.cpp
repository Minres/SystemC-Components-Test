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
 * sc_main.cpp
 *
 *  Created on: 17.09.2017
 *      Author: eyck@minres.com
 */

#include "simple_system.h"
#include <sysc/tracer.h>
#include <sysc/scv_tr_db.h>
#include <sysc/report.h>
#include <boost/program_options.hpp>
#include <sysc/report.h>
#include <sstream>

using namespace sysc;
namespace po = boost::program_options;

namespace {
const size_t ERROR_IN_COMMAND_LINE = 1;
const size_t SUCCESS = 0;
const size_t ERROR_UNHANDLED_EXCEPTION = 2;
} // namespace

int sc_main(int argc, char* argv[]){

	// Environment adaptations
	putenv(const_cast<char*>("SC_SIGNAL_WRITE_CHECK=DISABLE"));

//    sc_report_handler::set_handler(my_report_handler);
    sysc::Logger::reporting_level()=log::DEBUG;
    // todo: add module-name to log-file

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
    // todo: fix displayed clock period in VCD

    ///////////////////////////////////////////////////////////////////////////
    // instantiate top level
    ///////////////////////////////////////////////////////////////////////////
    simple_system i_simple_system("i_simple_system");
    //sr_report_handler::add_sc_object_to_filter(&i_simple_system.i_master, sc_core::SC_WARNING, sc_core::SC_MEDIUM);

    ///////////////////////////////////////////////////////////////////////////
    // run simulation
    ///////////////////////////////////////////////////////////////////////////
    sc_start(sc_core::sc_time(1, sc_core::SC_MS));
    // todo: provide end-of-simulation macros

    if(!sc_core::sc_end_of_simulation_invoked()) {
        LOG(logging::ERROR) << "simulation timed out";
    	sc_core::sc_stop();
    }
    return 0;
}

