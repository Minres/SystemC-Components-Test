cmake_minimum_required(VERSION 3.12)

if(SCV_FOUND)   
    add_subdirectory(transaction_recording)
endif()

add_subdirectory(simple_system)
add_subdirectory(ahb_bfm)
