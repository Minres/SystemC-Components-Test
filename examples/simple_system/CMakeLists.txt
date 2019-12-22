cmake_minimum_required(VERSION 3.3)
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
target_link_libraries (simple_system LINK_PUBLIC scc)
target_link_libraries (simple_system LINK_PUBLIC ${Boost_LIBRARIES} )
target_link_libraries (simple_system LINK_PUBLIC ${ZLIB_LIBRARY})
