cmake_minimum_required(VERSION 3.10)

project(Hiker)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_STANDARD_REQUIRED True)

set(SOURCE_FILES main.cpp)

add_subdirectory(hiker_management)
add_subdirectory(equipment_management)
add_subdirectory(identity_management)

add_executable(hiker ${SOURCE_FILES})

target_link_libraries(hiker PUBLIC hiker_management)
target_link_libraries(hiker PUBLIC equipment_management)
target_link_libraries(hiker PUBLIC identity_management)

target_link_directories(hiker PUBLIC "hiker_management")
target_link_directories(hiker PUBLIC "equipment_management")
target_link_directories(hiker PUBLIC "identity_management")

