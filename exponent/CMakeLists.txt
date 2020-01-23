cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project (Exponent)

find_package(gtest)

ENABLE_TESTING()

include_directories(
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}"
)

add_executable(ExponentCpp main.cpp)
target_link_libraries (ExponentCpp Exponent)

add_library(Exponent exponent.cpp)
add_executable(ExponentTest
    TestMain.cpp
    ExponentTest.cpp
)

TARGET_LINK_LIBRARIES(ExponentTest Exponent gtest pthread)
add_test(ExponentTest ExponentTest)
