cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project (BinarySearch)

find_package(gtest)

ENABLE_TESTING()

include_directories(
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}"
)

add_executable(BinarySearchCpp main.cpp)
target_link_libraries (BinarySearchCpp BinarySearch)

add_library(BinarySearch binary_search.cpp)
add_executable(BinarySearchTest
    TestMain.cpp
    BinarySearchTest.cpp
)

TARGET_LINK_LIBRARIES(BinarySearchTest BinarySearch gtest pthread)
add_test(BinarySearchTest BinarySearchTest)
