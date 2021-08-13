cmake_minimum_required(VERSION 3.10)
project(USBDongle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -I.. -g -fpic")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules")

# End Compiling Settings ---------------------------------------------------------------

# Begin SOURCE Files -------------------------------------------------------------------
message("--> Searching source files....")
file(GLOB SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/*.cpp *.c
        ../002-editedSample/thirdparty/license/*.cpp *.c
        ${PROJECT_SOURCE_DIR}/src/dialog/*.cpp *.c
        ${PROJECT_SOURCE_DIR}/src/filesystem/*.cpp *.c
        )

# Source Files Dump
foreach (_file ${SOURCE_FILES})
    message("Found: ${_file}")
endforeach ()
# End SOURCE Files -------------------------------------------------------------------

# Begin HEADER Files -------------------------------------------------------------------
message("--> Searching header files....")
file(GLOB HEADER_FILES
        ${PROJECT_SOURCE_DIR}/*.h *.hpp
        ../002-editedSample/thirdparty/license/*.h *.hpp
        ${PROJECT_SOURCE_DIR}/src/dialog/*.h *.hpp
        ${PROJECT_SOURCE_DIR}/src/filesystem/*.h *.hpp
        )

include_directories()
include_directories(src)

# Header Files Dump
foreach (_file ${HEADER_FILES})
    message("Found: ${_file}")
endforeach ()
# End HEADER Files -------------------------------------------------------------------


set(HASP_C_DIR /home/hakan/Downloads/Sentinel-LDK/API/Runtime/C/x86_64) # ${HASP_C_DIR}
set(HASP_CPP_DIR /home/hakan/Downloads/Sentinel-LDK/API/Runtime/Cpp/x86_64) # ${HASP_CPP_DIR}
set(HASP_CPP_LIB ${HASP_C_DIR}/libhasp_cpp_linux_x86_64.a) # ${HASP_CPP_LIB}

add_executable(${PROJECT_NAME}
        ${SOURCE_FILES}
        ${HEADER_FILES}
        ${RESOURCE_FILES}
        )

target_link_libraries(${PROJECT_NAME}
        ../002-editedSample/thirdparty/license/lib/libhasp_cpp_linux_x86_64.a
        ../002-editedSample/thirdparty/license/lib/libhasp_linux_x86_64_demo.so
        -lpthread
        )
