#include <iostream>

int n;

int main() {
  std::cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int s = 0; s < i; ++s) {
      std::cout << "*";
    }
    for (int m = 0; m < (2 * n) - (2 * i); ++m) {
      std::cout << " ";
    }
    for (int s = 0; s < i; ++s) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
  
  for (int i = n - 1; i > 0; --i) {
    for (int s = 0; s < i; ++s) {
      std::cout << "*";
    }
    for (int m = 0; m < (2 * n) - (2 * i); ++m) {
      std::cout << " ";
    }
    for (int s = 0; s < i; ++s) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}