cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project (MatrixRotate)

# find_package(gtest)

ENABLE_TESTING()

include_directories(
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}"
)

add_executable(MatrixRotateCpp main.cpp)
target_link_libraries (MatrixRotateCpp MatrixRotate)

add_library(MatrixRotate matrix_rotate.cpp)
add_executable(MatrixRotateTest
    TestMain.cpp
    MatrixRotateTest.cpp
)

TARGET_LINK_LIBRARIES(MatrixRotateTest MatrixRotate gtest pthread)
add_test(MatrixRotateTest MatrixRotateTest)
