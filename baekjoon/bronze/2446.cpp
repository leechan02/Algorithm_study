#include <iostream>
#include <cmath>

int n;

int main() {
  std::cin >> n;

  for (int i = n; i > 1; --i) {
    for (int s = 0; s < std::abs(i - n); ++s) {
      std::cout << " ";
    }
    for (int m = 0; m < (2 * i) - 1; ++m) {
      std::cout << "*";
    }
    std::cout << "\n";
  }

  for (int i = 0; i < n - 1; ++i) {
    std::cout << " ";
  }
  std::cout << "*\n";

  for (int i = 2; i <= n; ++i) {
    for (int s = 0; s < n - i; ++s) {
      std::cout << " ";
    }
    for (int m = 0; m < (2 * i) - 1; ++m) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}