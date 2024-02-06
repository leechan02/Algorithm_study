#include <iostream>

int main() {
  std::string str;
  std::string boom;
  std::cin >> str >> boom;

  std::string stack;
  for (int i = 0; i < str.size(); ++i) {
    if (boom.find(str[i]) == std::string::npos && stack.empty()) {
      stack.push_back(str[i]);
    } else if (str[i] == boom[boom.size() - 1]) {
      stack.push_back(str[i]);
      if (stack.size() >= boom.size() &&
          stack.substr(stack.size() - boom.size()) == boom) {
        for (int i = 0; i < boom.size(); ++i) {
          stack.pop_back();
        }
      }
    } else {
      stack.push_back(str[i]);
    }
  }
  if (stack.size()) {
    std::cout << stack << "\n";
  } else {
    std::cout << "FRULA\n";
  }
}