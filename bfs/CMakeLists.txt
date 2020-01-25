cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project (BFS)

find_package(gtest)

ENABLE_TESTING()

include_directories(
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}"
)

add_executable(BFSCpp main.cpp)
target_link_libraries (BFSCpp BFS)

add_library(BFS bfs.cpp)
add_executable(BFSTest
    TestMain.cpp
    BFSTest.cpp
)

TARGET_LINK_LIBRARIES(BFSTest BFS gtest pthread)
add_test(BFSTest BFSTest)
