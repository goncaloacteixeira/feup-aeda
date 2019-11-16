cmake_minimum_required(VERSION 3.10)
project(aeda1819_ci2)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)



add_executable(aeda1819_ci2 main.cpp Tests/tests.cpp Tests/CStack.h Tests/CSimpleList.h Tests/Kart.cpp)

target_link_libraries(aeda1819_ci2 gtest gtest_main)
