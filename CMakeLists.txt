cmake_minimum_required(VERSION 3.10)

project(PAOO_HWS)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES src/main.cpp src/hiker.cpp)

add_executable(hiker ${SOURCE_FILES})
