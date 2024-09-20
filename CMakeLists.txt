cmake_minimum_required(VERSION 3.10)

# Project name
project(MyCProject C)

# Enable testing
enable_testing()

# Find the CMocka package
find_package(CMocka REQUIRED)

# Include directories
include_directories(includes)

# Add all source files for the test executable
add_executable(lib_test test.c arrays.c anagram.c gcd.c linked-list.c PrimeTest.c)

# Link the cmocka library
target_link_libraries(lib_test cmocka)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Optionally, specify the build type (Debug or Release)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Specify compiler flags
set(CMAKE_C_FLAGS_DEBUG "-g -Wall")
set(CMAKE_C_FLAGS_RELEASE "-O3 -Wall")

# Output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Register lib_test as a CTest test
add_test(NAME lib_test COMMAND lib_test)

# Custom target for running tests with --output-on-failure
add_custom_target(run_tests
  COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  DEPENDS lib_test
  COMMENT "Running tests with output on failure"
)
