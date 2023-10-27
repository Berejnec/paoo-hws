cmake_minimum_required(VERSION 3.10)

project(PAOO_HWS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/main.hpp)

add_executable(hw_exe ${SOURCE_FILES})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/build)
