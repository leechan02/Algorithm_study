#include <iostream>
#include <algorithm>

int n, a, sum, max = -1001;

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a;
    sum += a;
    max = std::max(max, sum);
    if (sum < 0) {
      sum = 0;
    }
  }
  std::cout << max << "\n";
}