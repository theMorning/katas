#include <gtest/gtest.h>
#include "exponent.hpp"

TEST(ExponentTest, 2raised0) {
  int result = exponent(2, 0);
  ASSERT_EQ(result, 1);
}

TEST(ExponentTest, 2raised5) {
  int result = exponent(2, 5);
  ASSERT_EQ(result, 32);
}

TEST(ExponentTest, 5raised2) {
  int result = exponent(5, 2);
  ASSERT_EQ(result, 25);
}

TEST(ExponentTest, 4raised3) {
  int result = exponent(4, 3);
  ASSERT_EQ(result, 64);
}