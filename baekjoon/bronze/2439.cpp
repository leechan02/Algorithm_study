#include <iostream>

int n;

int main() {
  std::cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j < n - i) std::cout << " ";
      else std::cout << "*";
    }
    std::cout << "\n";
  }
}