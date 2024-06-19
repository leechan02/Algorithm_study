#include <iostream>

int n;

int main() {
  std::cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int j = n - i; j >= 0; --j) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}