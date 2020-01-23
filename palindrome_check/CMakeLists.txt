cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project (Palindrome)

find_package(gtest)

ENABLE_TESTING()

include_directories(
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}"
)

add_executable(PalindromeCpp main.cpp)
target_link_libraries (PalindromeCpp Palindrome)

add_library(Palindrome palindrome_check.cpp)
add_executable(PalindromeTest
    TestMain.cpp
    PalindromeTest.cpp
)

TARGET_LINK_LIBRARIES(PalindromeTest Palindrome gtest pthread)
add_test(PalindromeTest PalindromeTest)
