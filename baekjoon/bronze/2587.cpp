#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int tmp, avg, mid;
std::vector<int> num;

int main() {
  for (int i = 0; i < 5; ++i) {
    std::cin >> tmp;
    num.push_back(tmp);
  }
  std::sort(num.begin(), num.end());
  avg = std::accumulate(num.begin(), num.end(), 0) / 5;
  mid = num[2];
  std::cout << avg << "\n" << mid << "\n";
}