#include <iostream>

int main() {
  int n, m;

  std::cin >> n >> m;

  std::cout << "0 1" << std::endl;
  int root = 1;
  for (int i = 1; i < n - 1; i++) {
    std::cout << root << " " << i + 1 << std::endl;
    if (i >= m - 1) {
      root = i + 1;
    }
  }
  return 0;
}