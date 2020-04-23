cmake_minimum_required(VERSION 3.3)
add_executable (io_redirector_test
	main.cpp
)
target_link_libraries (io_redirector_test LINK_PUBLIC scc)
#target_link_libraries (io_redirector_test LINK_PUBLIC ${SystemC_LIBRARIES})
#target_link_libraries (io_redirector_test LINK_PUBLIC ${SCV_LIBRARIES})
#target_link_libraries (io_redirector_test LINK_PUBLIC ${Boost_LIBRARIES} )
#target_link_libraries (io_redirector_test LINK_PUBLIC ${CONAN_LIBS_LEVELDB})
#target_link_libraries (io_redirector_test LINK_PUBLIC ${ZLIB_LIBRARIES} )
#target_link_libraries (io_redirector_test LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries (io_redirector_test LINK_PUBLIC ${CMAKE_DL_LIBS})
