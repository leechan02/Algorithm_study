#include <iostream>
#include <string>
#include <algorithm>

bool inTag;
std::string s, result, tmp;

int main() {
  std::getline(std::cin, s);

  for (char c : s) {
    if (c == '<') {
      if (!tmp.empty()) {
        reverse(tmp.begin(), tmp.end());
        result += tmp;
        tmp.clear();
      }
      inTag = true;
      result += c;
    } else if (c == '>') {
      inTag = false;
      result += c;
    } else if (inTag) {
      result += c;
    } else {
      if (c == ' ') {
        if (!tmp.empty()) {
          reverse(tmp.begin(), tmp.end());
          result += tmp;
          tmp.clear();
        }
        result += c;
      } else {
        tmp += c;
      }
    }
  }

  if (!tmp.empty()) {
    reverse(tmp.begin(), tmp.end());
    result += tmp;
  }

  std::cout << result << "\n";
}