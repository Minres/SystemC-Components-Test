cmake_minimum_required(VERSION 3.3)
# Add executable called "transaction_recording" that is built from the source files
# "scv_tr_recording_example.cpp". The extensions are automatically found.
add_executable (transaction_recording
	scv_tr_recording_example.cpp
)
# Link the executable to the sc_components library. Since the sc_components library has
# public include directories we will use those link directories when building
# transaction_recording
target_link_libraries (transaction_recording LINK_PUBLIC scc)
#target_link_libraries (transaction_recording LINK_PUBLIC ${Boost_LIBRARIES} )
#target_link_libraries (transaction_recording LINK_PUBLIC ${CONAN_LIBS_LEVELDB})
#target_link_libraries (transaction_recording LINK_PUBLIC ${ZLIB_LIBRARIES} )
#target_link_libraries (transaction_recording LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries (transaction_recording LINK_PUBLIC ${CMAKE_DL_LIBS})
