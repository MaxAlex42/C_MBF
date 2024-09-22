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
add_executable(lib_test test.c arrays.c anagram.c gcd.c linked-list.c PrimeTest.c test-arrays.c)

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

# Add coverage flags for gcovr when in Debug mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

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

# Find gcovr and create a custom target for coverage
find_program(GCOVR gcovr)
if(GCOVR)
  add_custom_target(coverage
    COMMAND ${GCOVR} --root ${CMAKE_SOURCE_DIR} --exclude-directories "tests/" --branches --verbose
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running gcovr to show coverage..."
  )
endif()

# Optionally add a clean target to remove coverage files
add_custom_target(clean_coverage
  COMMAND find . -name "*.gcda" -o -name "*.gcno" -exec rm -f {} \;
  COMMENT "Cleaning up coverage files..."
)