cmake_minimum_required(VERSION 3.10)
project(aeda1617_ci3)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)



add_executable(aeda1617_ci3 main.cpp Tests/BST.h Tests/Book.cpp Tests/Book.h Tests/ReadingClub.cpp Tests/ReadingClub.h Tests/User.cpp Tests/User.h Tests/Test.cpp)

target_link_libraries(aeda1617_ci3 gtest gtest_main)
