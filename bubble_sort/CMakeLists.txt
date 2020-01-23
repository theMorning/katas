cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project (BubbleSort)

find_package(gtest)

ENABLE_TESTING()


# [rmorning@3113 build]$ for file in $(find CMakeFiles -name *.o) ; do gcov $file ; done
# #!/bin/bash

# set -euo pipefail

# mkdir -p build && cd build

# # Configure
# cmake -DCODE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug ..
# # Build (for Make on Unix equivalent to `make -j $(nproc)`)
# cmake --build . --config Debug -- -j $(nproc)
# # Test
# ctest -j $(nproc) --output-on-failure
option(CODE_COVERAGE "Enable coverage reporting" ON)



# The version number.
# set (KATA_VERSION_MAJOR 1)
# set (KATA_VERSION_MINOR 0)

# Greetings
include_directories(
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}"
)

# configure_file (
#   "${PROJECT_SOURCE_DIR}/KataConfig.h.in"
#   "${PROJECT_BINARY_DIR}/KataConfig.h"
# )

add_executable(BubbleSortCpp main.cpp)
target_link_libraries (BubbleSortCpp BubbleSort)

add_library(BubbleSort bubble_sort.cpp)
add_executable(BubbleSortTest
    TestMain.cpp
    BubbleSortTest.cpp
)
# IF(CODE_COVERAGE)
if(CMAKE_COMPILER_IS_GNUCXX)
LIST(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules")
include(CodeCoverage)
APPEND_COVERAGE_COMPILER_FLAGS()
#991   git clone https://github.com/linux-test-project/lcov.git
# set(COVERAGE_LCOV_EXCLUDES 'dir1/*' 'dir2/*') // this is optional if you want to exclude some directory from the report
SETUP_TARGET_FOR_COVERAGE_LCOV(NAME foo_coverage
                              EXECUTABLE BubbleSortTest
                              DEPENDENCIES BubbleSort)
endif()
# ENDIF()
TARGET_LINK_LIBRARIES(BubbleSortTest BubbleSort gtest pthread)
add_test(BubbleSortTest BubbleSortTest)

