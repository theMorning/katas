#include <sstream>
#include <gtest/gtest.h>
#include "binary_search.hpp"

TEST(BinarySearchTest, EmptyArray) {
  int sorted_arr[0] = {};
  int find = 0;
  int found = binary_search(find, sorted_arr, 0);
  ASSERT_EQ(found, -1);
}

TEST(BinarySearchTest, ArrayOfOne) {
  int sorted_arr[1] = {0};
  int find = 0;
  int found = binary_search(find, sorted_arr, 1);
  ASSERT_EQ(found, 0);
}

TEST(BinarySearchTest, ArrayOfTwoFindFirst) {
  int sorted_arr[2] = {0,1};
  int find = 0;
  int found = binary_search(find, sorted_arr, 2);
  ASSERT_EQ(found, 0);
}

TEST(BinarySearchTest, ArrayOfTwoFindSecond) {
  int sorted_arr[2] = {0,1};
  int find = 1;
  int found = binary_search(find, sorted_arr, 2);
  ASSERT_EQ(found, 1);
}

TEST(BinarySearchTest, ArrayOfThreeNotFound) {
  int sorted_arr[3] = {0,1,2};
  int find = 42;
  int found = binary_search(find, sorted_arr, 3);
  ASSERT_EQ(found, -1);
}

TEST(BinarySearchTest, ArrayOfThreeFindFirst) {
  int sorted_arr[3] = {0,1,2};
  int find = 0;
  int found = binary_search(find, sorted_arr, 3);
  ASSERT_EQ(found, 0);
}

TEST(BinarySearchTest, ArrayOfThreeFindSecond) {
  int sorted_arr[3] = {0,1,2};
  int find = 1;
  int found = binary_search(find, sorted_arr, 3);
  ASSERT_EQ(found, 1);
}

TEST(BinarySearchTest, ArrayOfThreeFindThird) {
  int sorted_arr[3] = {0,1,2};
  int find = 2;
  int found = binary_search(find, sorted_arr, 3);
  ASSERT_EQ(found, 2);
}

TEST(BinarySearchTest, ArrayOfFiveSearchLeftThenRight) {
  int sorted_arr[5] = {0,1,2,4,5};
  int find = 1;
  int found = binary_search(find, sorted_arr, 5);
  ASSERT_EQ(found, 1);
}

TEST(BinarySearchTest, ArrayOfFiveSearchRighThenLeft) {
  int sorted_arr[5] = {0,1,2,4,5};
  int find = 4;
  int found = binary_search(find, sorted_arr, 5);
  ASSERT_EQ(found, 3);
}

TEST(BinarySearchTest, RealExample) {
  int sorted_arr[8] = {1, 3, 7, 20, 27, 36, 42, 79};
  int find = 42;
  int found = binary_search(find, sorted_arr, 8);
  ASSERT_EQ(found, 6);
}
