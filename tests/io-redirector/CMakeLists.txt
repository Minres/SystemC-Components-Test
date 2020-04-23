cmake_minimum_required(VERSION 3.12)
add_executable (io_redirector_test
	main.cpp
)
target_link_libraries (io_redirector_test LINK_PUBLIC scc)
