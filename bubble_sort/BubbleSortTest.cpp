#include <gtest/gtest.h>
#include "bubble_sort.hpp"

/*
test skeleton

TEST(BubbleSortTest, AssertEqual) {
  // do stuff
  ASSERT_EQ(arr[i], ans[i]);
}
*/

TEST(SwapTest, SwapZeroes) {
  int first = 0;
  int second = 0;
  swap(&first, &second);
  ASSERT_EQ(first, 0);
  ASSERT_EQ(second, 0);
}

TEST(SwapTest, SwapZeroOne) {
  int first = 0;
  int second = 1;
  swap(&first, &second);
  ASSERT_EQ(first, 1);
  ASSERT_EQ(second, 0);
}

TEST(BubbleSortTest, SingleElement) {
  int arr[] = {0};
  int ans[] = {0};
  int n = 0;

  bubble_sort(arr, n);
  for(int i = 0; i < n; i++) {
    ASSERT_EQ(arr[i], ans[i]);
  }
}

TEST(BubbleSortTest, PreSorted) {
  int arr[] = {0,1,2,3};
  int ans[] = {0,1,2,3};
  int n = sizeof(arr) / sizeof(arr[0]);

  bubble_sort(arr, n);
  for(int i = 0; i < n; i++) {
    ASSERT_EQ(arr[i], ans[i]);
  }
}

TEST(BubbleSortTest, Reversed) {
  int arr[] = {3,2,1,0};
  int ans[] = {0,1,2,3};
  int n = sizeof(arr) / sizeof(arr[0]);

  bubble_sort(arr, n);
  for(int i = 0; i < n; i++) {
    ASSERT_EQ(arr[i], ans[i]);
  }
}

TEST(BubbleSortTest, NegativeNumbers) {
  int arr[] = {-1,-2,-6,-4,0};
  int ans[] = {-6,-4,-2,-1,0};
  int n = sizeof(arr) / sizeof(arr[0]);

  bubble_sort(arr, n);
  for(int i = 0; i < n; i++) {
    ASSERT_EQ(arr[i], ans[i]);
  }
}

TEST(BubbleSortTest, Unordered) {
  int arr[] = {6,3,4,2,1,5};
  int ans[] = {1,2,3,4,5,6};
  int n = sizeof(arr) / sizeof(arr[0]);

  bubble_sort(arr, n);
  for(int i = 0; i < n; i++) {
    ASSERT_EQ(arr[i], ans[i]);
  }
}
