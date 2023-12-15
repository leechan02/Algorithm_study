#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> arr(N, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> arr[i];
  }
  std::sort(arr.begin(), arr.end());

  int ans = 0, sum;
  std::cout << ans << '\n';
  return (0);
}