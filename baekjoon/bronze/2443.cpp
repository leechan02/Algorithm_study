#include <iostream>
#include <cmath>

int n;

int main() {
  std::cin >> n;

  for (int i = n; i > 0; --i) {
    for (int f = 0; f < std::abs(i - n); ++f) {
      std::cout << " ";
    }
    for (int s = 0; s < (2 * i - 1); ++s) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}