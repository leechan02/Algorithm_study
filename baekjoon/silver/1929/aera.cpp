#include <iostream>
#include <vector>

int main() {
  int M, N;
  std::cin >> M >> N;

  std::vector<int> arr;
  for (int i = 2; i <= N; ++i) {
    arr.push_back(i);
  }

  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] == 0) {
      continue;
    }
    for (int j = i + arr[i]; j < arr.size(); j += arr[i]) {
      arr[j] = 0;
    }
  }
  for (auto i : arr) {
    if (i >= M) {
      std::cout << i << "\n";
    }
  }
  return (0);
}