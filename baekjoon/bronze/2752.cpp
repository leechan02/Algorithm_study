#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int tmp;
  std::vector<int> arr(3);

  for (int i = 0; i < 3; ++i) {
    std::cin >> tmp;
    arr[i] = tmp;
  }
  std::sort(arr.begin(), arr.end());
  for (auto i : arr) {
    std::cout << i << " ";
  }
}