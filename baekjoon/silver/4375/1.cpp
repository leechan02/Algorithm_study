#include <iostream>

int n;

int main() {
  while (std::cin >> n) {
    int remainder = 1 % n;

    for (int length = 1;; ++length) {
      if (remainder == 0) {
        std::cout << length << "\n";
        break;
      }

      remainder = (remainder * 10 + 1) % n;
    }
  }
  return 0;
}
