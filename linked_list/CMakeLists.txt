cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project (LinkedList)

ENABLE_TESTING()

include_directories(
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}"
)

add_executable(LinkedListCpp main.cpp)

add_executable(LinkedListTest
    TestMain.cpp
    LinkedListTest.cpp
)

TARGET_LINK_LIBRARIES(LinkedListTest
  gtest
  pthread
)
add_test(LinkedListTest LinkedListTest)
