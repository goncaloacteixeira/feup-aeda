cmake_minimum_required(VERSION 3.10)
project(aeda1920_fp04)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)



add_executable(aeda1920_fp04 main.cpp Tests/tests.cpp Tests/parque.cpp Tests/sequentialSearch.h Tests/insertionSort.h)

target_link_libraries(aeda1920_fp04 gtest gtest_main)
