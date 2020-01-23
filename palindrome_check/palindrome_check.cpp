#include <string>

using std::string;

bool palindrome_check(string s1, string s2) {
  if (s1.size() != s2.size()) {
    return false;
  }

  int s1_position = 0;
  while (s1_position < s1.size()) {
    if (s1.at(s1_position) == s2.at(s2.size() - s1_position - 1)) {
      s1_position++;
    } else {
      return false;
    }
  }

  return true;
}
