#include <iostream>
#include <vector>
#include <algorithm>

int tmp, result;
std::vector<int> num;

int main() {
  for (int i = 0; i < 7; ++i) {
    std::cin >> tmp;
    if (tmp % 2 == 1) num.push_back(tmp);
  }

  if (num.size() == 0) {
    std::cout << "-1\n";
  } else {
    std::sort(num.begin(), num.end());
    for (auto i : num) {
      result += i;
    }
    std::cout << result << "\n" << num[0] << "\n";
  }
}