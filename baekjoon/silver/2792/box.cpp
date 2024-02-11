#include <iostream>
#include <climits>
#include <algorithm>

long long n, m, color[300004], ans = LONG_MAX;

bool check(long long mid) {
  long long num = 0;
  for (int i = 0; i < m; ++i) {
    num += color[i] / mid;
    if (color[i] % mid) ++num;
  }
  return n >= num;
}

int main() {
  std::cin >> n >> m;

  long long low = 1, high = 0, mid;
  for (int i = 0; i < m; ++i) {
    std::cin >> color[i];
    high = std::max(high, color[i]);
  }
  while (low <= high) {
    mid = (low + high) / 2;
    if (check(mid)) {
      ans = std::min(ans, mid);
      high = mid - 1;
    } else low = mid + 1;
  }
  std::cout << ans << "\n";
}