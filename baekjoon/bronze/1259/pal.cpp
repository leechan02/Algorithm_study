#include <iostream>

std::string str;

int main() {
  while (std::cin >> str) {
    if (str == "0") {
      break;
    }

    std::string tmp = str;
    std::reverse(tmp.begin(), tmp.end());
    if (str == tmp) {
      std::cout << "yes\n";
    } else {
      std::cout << "no\n";
    }
  }
  return (0);
}