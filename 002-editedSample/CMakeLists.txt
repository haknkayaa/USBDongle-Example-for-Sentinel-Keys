cmake_minimum_required(VERSION 3.10)
project(USBDongle)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -I.. -g -fpic")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules")

# End Compiling Settings ---------------------------------------------------------------

# Begin SOURCE Files -------------------------------------------------------------------
message("--> Searching source files....")
file(GLOB SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/application/*.cpp *.c
        ${PROJECT_SOURCE_DIR}/thirdparty/license/*.cpp *.c
        )

# Source Files Dump
foreach (_file ${SOURCE_FILES})
    message("Found: ${_file}")
endforeach ()
# End SOURCE Files -------------------------------------------------------------------

# Begin HEADER Files -------------------------------------------------------------------
message("--> Searching header files....")
file(GLOB HEADER_FILES
        ${PROJECT_SOURCE_DIR}/application/*.h
        ${PROJECT_SOURCE_DIR}/thirdparty/license/*.h
        )

include_directories()
include_directories(application)

# Header Files Dump
foreach (_file ${HEADER_FILES})
    message("Found: ${_file}")
endforeach ()
# End HEADER Files -------------------------------------------------------------------

# Begin UI Files ---------------------------------------------------------------------
message("--> Searching UI files....")
set(CMAKE_AUTOUIC_SEARCH_PATHS uis)
file(GLOB UI_FILES ${PROJECT_SOURCE_DIR}/uis/*.ui)
message("Found: ${UI_FILES}")
# End UI Files ------------------------------------------------------------------

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)
find_package(Qt5 COMPONENTS Xml REQUIRED)
find_package(Qt5 COMPONENTS OpenGL REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
find_package(Qt5 COMPONENTS Sql REQUIRED)
find_package(Qt5 COMPONENTS PrintSupport REQUIRED)
find_package(Qt5 COMPONENTS Charts REQUIRED)
find_package(Qt5 COMPONENTS Svg REQUIRED)
find_package(Qt5 COMPONENTS Xml REQUIRED)

message("--> Printing QT5 Modules")
message("Qt5               : " ${Qt5_DIR})
message("Qt5Core           : " ${Qt5Core_DIR})
message("Qt5Widgets        : " ${Qt5Widgets_DIR})
message("Qt5Gui            : " ${Qt5Gui_DIR})
message("Qt5OpenGL         : " ${Qt5OpenGL_DIR})

message("--> Printing Qt5 Libraries")
get_target_property(QtCore_location Qt5::Core LOCATION)
message("Qt5::Core Lib    : ${QtCore_location}")
get_target_property(QtWidgets_location Qt5::Widgets LOCATION)
message("Qt5::Widgets Lib : ${QtWidgets_location}")
get_target_property(QtGui_location Qt5::Gui LOCATION)
message("Qt5::Gui Lib     : ${QtGui_location}")

add_executable(${PROJECT_NAME}
        ${SOURCE_FILES}
        ${HEADER_FILES}
        ${RESOURCE_FILES}
        )

target_link_libraries(${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/thirdparty/license/lib/libhasp_cpp_linux_x86_64.a
        ${PROJECT_SOURCE_DIR}/thirdparty/license/lib/libhasp_linux_x86_64_demo.so
        -lpthread

        Qt5::Core
        Qt5::Widgets
        Qt5::Xml
        Qt5::Network
        Qt5::Sql
        Qt5::PrintSupport
        Qt5::Charts
        Qt5::Svg
        Qt5::OpenGL
        )
