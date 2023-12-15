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

  int ans = 0, sum, first = 0, last = N - 1;
  while (first + 1 < N - 1 && arr[first + 1] <= 0) {
    sum = arr[first] * arr[first + 1];
    ans += sum;
    first += 2;
  }
  while (first - 2 < last - 1 && arr[last - 1] > 1) {
    sum = arr[last] * arr[last - 1];
    ans += sum;
    last -= 2;
  }
  while (first <= last) {
    ans += arr[first++];
  }
  std::cout << ans << '\n';
  return (0);
}