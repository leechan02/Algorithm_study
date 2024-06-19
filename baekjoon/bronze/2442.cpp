#include <iostream>

int n;

int main() {
  std::cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int f = 1; f < (n - (2 * i - 1) / 2); ++f) {
      std::cout << " ";
    }
    for (int s = 0; s < (2 * i - 1); ++s) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}