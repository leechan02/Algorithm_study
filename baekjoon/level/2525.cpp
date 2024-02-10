#include <iostream>

int h, m, t, sum;

int main() {
  std::cin >> h >> m >> t;

  sum = h * 60 + m + t;
  if (sum >= 1440) {
    std::cout << (sum - 1440) / 60 << " " << (sum - 1440) % 60 << "\n";
  } else {
    std::cout << sum / 60 << " " << sum % 60 << "\n";
  }
}