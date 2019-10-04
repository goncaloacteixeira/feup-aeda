cmake_minimum_required(VERSION 3.10)
project(aeda1920_fp02_extra)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aeda1920_fp02_extra main.cpp Tests/tests.cpp Tests/veterinario.cpp Tests/animal.cpp Tests/zoo.cpp)

target_link_libraries(aeda1920_fp02_extra gtest gtest_main)
