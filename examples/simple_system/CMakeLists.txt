#-------------------------------------------------------------------------------
# Copyright 2017 eyck@minres.com
# 
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License.  You may obtain a copy
# of the License at
# 
#   http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#-------------------------------------------------------------------------------
cmake_minimum_required (VERSION 2.8.12)

# Add executable called "simple_system" that is built from the source files
# "scv_tr_recording_example.cpp". The extensions are automatically found.
add_executable (simple_system 
    plic.cpp
    uart.cpp
    spi.cpp
    gpio.cpp
    test_initiator.cpp
    simple_system.cpp
    sc_main.cpp
)

# Link the executable to the sc_components library. Since the sc_components library has
# public include directories we will use those link directories when building
# simple_system
target_link_libraries (simple_system LINK_PUBLIC sc-components)
target_link_libraries (simple_system LINK_PUBLIC ${SystemC_LIBRARIES})
target_link_libraries (simple_system LINK_PUBLIC ${SCV_LIBRARIES})
target_link_libraries (simple_system LINK_PUBLIC ${Boost_LIBRARIES} )
target_link_libraries (simple_system LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (simple_system LINK_PUBLIC ${ZLIB_LIBRARY})
target_link_libraries (simple_system LINK_PUBLIC ${CMAKE_DL_LIBS})
