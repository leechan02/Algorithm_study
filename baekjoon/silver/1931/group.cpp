#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<std::pair<int, int>> arr(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> arr[i].second >> arr[i].first;
  }
  std::sort(arr.begin(), arr.end());

  int end = -1, cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (arr[i].second >= end) {
      end = arr[i].first;
      cnt++;
    }
  }
  std::cout << cnt << '\n';
  return (0);
}