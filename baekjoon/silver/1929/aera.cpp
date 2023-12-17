#include <iostream>
#include <vector>

int main() {
  int M, N;
  std::cin >> M >> N;

  std::vector<int> arr(N + 1, 0);
  for (int i = 0; i <= N; ++i) {
    arr[i] = i;
  }

  for (int i = 0; i < arr.size(); ++i) {
    for (int j = i + 1; j < arr.size(); ++j) {
      if (arr[j] && arr[i] && arr[j] % arr[i] == 0) {
        arr.erase(arr.begin() + j);
      }
    }
  }
  for (auto i : arr) {
    if (i >= M) {
      std::cout << i << "\n";
    }
  }
  return (0);
}