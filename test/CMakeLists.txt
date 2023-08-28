cmake_minimum_required(VERSION 3.23)

project(elaborato)

add_subdirectory("./lib/googletest-main")
set(gtest_SOURCE_DIR, "./lib/googletest-main")
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES test.cpp)
add_executable(runTest ${TEST_SOURCE_FILES})
target_link_libraries(runTest gtest gtest_main core)
