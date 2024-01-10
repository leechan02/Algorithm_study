#include <iostream>

int main() {
  std::string str;
  std::cin >> str;

  int check = str.size() / 2;
  for(int i = 0; i < check; ++i) {
    if (str[i] != str[str.size() - 1 - i]) {
      std::cout << "0\n";
      return (0);
    }
  }
  std::cout << "1\n";
  return (0);
}