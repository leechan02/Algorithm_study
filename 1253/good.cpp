#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  long long N;
  std::cin >> N;

  std::vector<long long> arr(N, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  long long start, end, tmp, count = 0;
  for (long long sum = 0; sum < N; ++sum) {
    start = 0, end = N - 1;
    while (start < end) {
      if (start == sum)
        start++;
      if (end == sum)
        end--;
      if (start >= end)
        break;

      tmp = arr[start] + arr[end];
      if (tmp == arr[sum]) {
        count++;
        break;
      } else if (tmp > arr[sum]) {
        end--;
      } else {
        start++;
      }
    }
  }
  std::cout << count << '\n';
}