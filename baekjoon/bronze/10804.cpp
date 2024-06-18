#include <iostream>
#include <vector>
#include <algorithm>

int a, b;
std::vector<int> arr;

int main() {
  for (int i = 1; i <= 20; ++i) {
    arr.push_back(i);
  }

  for (int i = 0; i < 10; ++i) {
    std::cin >> a >> b;
    std::reverse(arr.begin() + a - 1, arr.begin() + b);
  }

  for (auto i : arr) {
    std::cout << i << " ";
  }
}