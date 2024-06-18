#include <iostream>

int n, x, tmp;

int main() {
  std::cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;
    if (tmp < x) std::cout << tmp << " ";
  }
}