cmake_minimum_required(VERSION 3.10)
project(aeda1819_ci3)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)



add_executable(aeda1819_ci3 main.cpp Tests/BST.h Tests/Client.cpp Tests/Client.h Tests/ClientRecord.h Tests/ClientRecord.cpp Tests/Property.cpp Tests/Property.h Tests/PropertyTypeItem.h Tests/PropertyTypeItem.cpp Tests/REAgency.cpp Tests/REAgency.h Tests/Test.cpp)

target_link_libraries(aeda1819_ci3 gtest gtest_main)
