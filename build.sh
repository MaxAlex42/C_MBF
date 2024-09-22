#!/bin/bash

# Set variables
BUILD_DIR="build"

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
  mkdir "$BUILD_DIR"
fi

# Navigate to the build directory
cd "$BUILD_DIR" || exit

# Run CMake to configure the project
echo "Configuring the project..."
cmake .. || { echo "CMake configuration failed"; exit 1; }

# Build the project
echo "Building the project..."
cmake --build . || { echo "Build failed"; exit 1; }

# Run the tests
echo "Running the tests..."
cmake --build . --target run_tests || { echo "Tests failed"; exit 1; }

# Run gcovr to show coverage results in the terminal
echo "Generating code coverage report..."
cmake --build . --target coverage || { echo "Coverage report generation failed"; exit 1; }

# Optionally, return to the original directory
cd ..