#include <iostream>

int n, lis[1004], len, num;

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    auto lowerPos = std::lower_bound(lis, lis + len, num);
    if (*lowerPos == 0) len++;
    *lowerPos = num;
  }
  std::cout << len << "\n";
}