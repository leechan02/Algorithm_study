#include <iostream>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  long long N, k;
  std::cin >> N >> k;

  long long start = 1, end = k, ans = 0;
  while (start <= end) {
    long long mid = (start + end) / 2;
    long long cnt = 0;
    for (long long i = 1; i <= N; ++i) {
      cnt += std::min(mid / i, N);
    }
    if (cnt < k) {
      start = mid + 1;
    } else {
      ans = mid;
      end = mid - 1;
    }
  }
  std::cout << ans << '\n';

  return (0);
}

// 1 2 3 4
// 2 4 6 8
// 3 6 9 12
// 4 8 12 16

// 1 2 2 3 3 4 4 4 6 6 8 8 9 12 12 16

// 1 2 3
// 2 4 6
// 3 6 9

// 1 2 2 3 3 4 6 6 9

