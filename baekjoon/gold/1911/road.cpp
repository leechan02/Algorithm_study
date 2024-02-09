#include <iostream>
#include <vector>
#include <algorithm>

int n, l, idx, ans, cnt, size;

int main() {
  std::cin >> n >> l;

  std::vector<std::pair<int, int>> water(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> water[i].first >> water[i].second;
  }
  std::sort(water.begin(), water.end());
  for (int i = 0; i < n; ++i) {
    if (water[i].second <= idx) continue;
    if (idx < water[i].first) {
      size = water[i].second - water[i].first;
      cnt = size / l + (size % l ? 1 : 0);
      idx = water[i].first + cnt * l;
    } else {
      size = water[i].second - idx;
      cnt = size / l + (size % l ? 1 : 0);
      idx = idx + cnt * l;
    }
    ans += cnt;
  }
  std::cout << ans << "\n";
}