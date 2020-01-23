#include <gtest/gtest.h>
#include "palindrome_check.hpp"

TEST(PalindromeTest, Empty) {
  bool result = palindrome_check("", "");
  ASSERT_EQ(result, true);
}

TEST(PalindromeTest, DifferentSize) {
  bool result = palindrome_check("a", "abc");
  ASSERT_EQ(result, false);
}

TEST(PalindromeTest, SingleCharacterPalindrome) {
  bool result = palindrome_check("a", "a");
  ASSERT_EQ(result, true);
}

TEST(PalindromeTest, SingleCharacterNotPalindrome) {
  bool result = palindrome_check("a", "b");
  ASSERT_EQ(result, false);
}

TEST(PalindromeTest, TwoCharacterPalindrome) {
  bool result = palindrome_check("aa", "aa");
  ASSERT_EQ(result, true);
}

TEST(PalindromeTest, TwoCharacterNotPalindrome) {
  bool result = palindrome_check("aa", "ba");
  ASSERT_EQ(result, false);
}

TEST(PalindromeTest, ThreeCharacterPalindrome) {
  bool result = palindrome_check("aba", "aba");
  ASSERT_EQ(result, true);
}

TEST(PalindromeTest, ThreeCharacterNotPalindrome) {
  bool result = palindrome_check("aab", "aba");
  ASSERT_EQ(result, false);
}

TEST(PalindromeTest, racecar) {
  bool result = palindrome_check("racecar", "racecar");
  ASSERT_EQ(result, true);
}

TEST(PalindromeTest, sweet_teews) {
  bool result = palindrome_check("sweet", "teews");
  ASSERT_EQ(result, true);
}

TEST(PalindromeTest, dennis_ritchie) {
  bool result = palindrome_check("dennis", "ritchie");
  ASSERT_EQ(result, false);
}