#include <iostream>

int main() {
  int n;
  std::cin >> n;
  if (n >= 90 && n <= 100) {
    std::cout << "A\n";
  } else if (n >= 80 && n < 90) {
    std::cout << "B\n";
  } else if (n >= 70 && n < 80) {
    std::cout << "C\n";
  } else if (n >= 60 && n < 70) {
    std::cout << "D\n";
  } else {
    std::cout << "F\n";
  }
}