#include <iostream>
#include <vector>
#include <algorithm>

int tmp, max, max_index;
std::vector<int> num;

int main() {
  for (int i = 0; i < 9; ++i) {
    std::cin >> tmp;
    num.push_back(tmp);
  }

  auto max_it = std::max_element(num.begin(), num.end());
  max = *max_it;
  max_index = std::distance(num.begin(), max_it);

  std::cout << max << "\n" << max_index + 1;
}