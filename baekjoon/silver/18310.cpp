#include <iostream>
#include <vector>
#include <algorithm>

int n, num;
std::vector<int> house;

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    house.push_back(num);
  }
  std::sort(house.begin(), house.end());
  std::cout << ((n % 2 == 0) ? house[n / 2 - 1] : house[n / 2]) << "\n";
}