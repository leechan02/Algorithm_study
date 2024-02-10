#include <iostream>

int main() {

  int n;
  std::cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < n - i; k++) std::cout << ' ';
    for (int k = 0; k < i + (i - 1); k++) std::cout << '*';
    std::cout << '\n';
  }
  for (int i = n - 1; i > 0; i--) {
    for (int k = 0; k < n - i; k++) std::cout << ' ';
    for (int k = 0; k < i + (i - 1); k++) std::cout << '*';
    std::cout << '\n';
  }
}