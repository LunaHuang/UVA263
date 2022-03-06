cmake_minimum_required(VERSION 3.0.0)
project(UVA263 VERSION 0.1.0)

include(CTest)
enable_testing()

option(WITH_GTEST "Enable Google Test" OFF)

if(WITH_GTEST)
  find_package(GTest CONFIG REQUIRED)
  MESSAGE("Enable Google Test")
  ADD_DEFINITIONS("-DWITH_GTEST")
endif()

add_executable(uva263 main.cpp)
if(WITH_GTEST)
target_link_libraries(uva263 GTest::gtest)
endif()

