cmake_minimum_required(VERSION 3.12)
add_executable (simple_system 
    plic.cpp
    uart.cpp
    spi.cpp
    gpio.cpp
    test_initiator.cpp
    simple_system.cpp
    sc_main.cpp
)
target_link_libraries (simple_system LINK_PUBLIC scc)
target_link_libraries (simple_system LINK_PUBLIC ${Boost_LIBRARIES} )
