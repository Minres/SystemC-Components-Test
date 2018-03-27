cmake_minimum_required(VERSION 3.3)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_CURRENT_SOURCE_DIR}/sc-components/cmake)

include(GitFunctions)
get_branch_from_git()

### set the directory names of the submodules
set(GIT_SUBMODULES sc-components)
set(GIT_SUBMODULE_DIR_sc-components .)
### set each submodules's commit or tag that is to be checked out
### (leave empty if you want master)
#set(GIT_SUBMODULE_VERSION_sc-components 3af6b9836589b082c19d9131c5d0b7afa8ddd7cd)
set(GIT_SUBMODULE_BRANCH_sc-components ${GIT_BRANCH})

include(GNUInstallDirs)
include(Submodules)
include(Conan)

#enable_testing() 

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
    set(CMAKE_CXX_FLAG_RELEASE "-O2 -DNDEBUG")
    set(CMAKE_C_FLAG_RELEASE "-O2 -DNDEBUG")
    set(CMAKE_CXX_FLAG_DEBUG "-Og")
    set(CMAKE_C_FLAG_DEBUG "-Og")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()

setup_conan()

# This line finds the boost lib and headers. 
set(Boost_NO_BOOST_CMAKE ON) #  Don't do a find_package in config mode before searching for a regular boost install.
find_package(Boost COMPONENTS program_options system thread REQUIRED)

# set-up SystemC and SCV
find_package(SystemC)
if(SystemC_FOUND)
    add_definitions(-DWITH_SYSTEMC)
    include_directories(${SystemC_INCLUDE_DIRS})
    link_directories(${SystemC_LIBRARY_DIRS})
else()
    message( FATAL_ERROR "SystemC library not found." )
endif()

if(CCI_FOUND)
    include_directories(${CCI_INCLUDE_DIRS})
    link_directories(${CCI_LIBRARY_DIRS})
else()
    message( FATAL_ERROR "SystemC CCI library not found." )
endif()

if(SCV_FOUND)   
    add_definitions(-DWITH_SCV)
    link_directories(${SCV_LIBRARY_DIRS})
endif()

set(PROJECT_3PARTY_DIRS external sr_report sr_signal)
include(sc-components/cmake/clang-format.cmake)

add_subdirectory(sc-components)
add_subdirectory(examples)
#add_subdirectory(test)

#
# SYSTEM PACKAGING (RPM, TGZ, ...)
# _____________________________________________________________________________

#include(CPackConfig)

#
# CMAKE PACKAGING (for other CMake projects to use this one easily)
# _____________________________________________________________________________

#include(PackageConfigurator)

