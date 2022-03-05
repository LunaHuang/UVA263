cmake_minimum_required(VERSION 3.0.0)
project(UVA263 VERSION 0.1.0)

find_package(GTest CONFIG REQUIRED)
include(CTest)
enable_testing()

add_executable(uva263 main.cpp)
target_link_libraries(uva263 GTest::gtest)

add_test(uva263 test0)
add_test(uva263 test1)
