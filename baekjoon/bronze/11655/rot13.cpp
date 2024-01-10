#include <iostream>

std::string str;

int main() {
  std::getline(std::cin, str);

  for (int i = 0; i < str.size(); ++i) {
    if ((str[i] >= 'A' && str[i] <= 'M') || (str[i] >= 'a' && str[i] <= 'm')) {
      std::cout << (char)(str[i] + 13);
    } else if ((str[i] >= 'N' && str[i] <= 'Z') ||
               (str[i] >= 'n' && str[i] <= 'z')) {
      std::cout << (char)(str[i] - 13);
    } else {
      std::cout << str[i];
    }
  }
  return (0);
}