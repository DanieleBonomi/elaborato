#find_package(GTest REQUIRED)

set(SOURCE_FILES test1.cpp test1.h)

#target_link_libraries(runAllTests ${GTEST_BOTH_LIBRARIES})


# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run ${SOURCE_FILES})
target_link_libraries(Google_Tests_run gtest gtest_main)

