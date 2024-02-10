#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int n, ans, sum, idx = INT_MIN;

int main() {
  std::ios::sync_with_stdio(0); std::cout.tie(0); std::cin.tie(0);
  std::cin >> n;
  std::vector<std::pair<int, int>> line(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> line[i].first >> line[i].second;
  }
  std::sort(line.begin(), line.end());

  for (int i = 0; i < n; ++i) {
    if (line[i].second < idx) continue;
    if (idx < line[i].first) {
      sum = line[i].second - line[i].first;
    } else {
      sum = line[i].second - idx;
    }
    idx = line[i].second;
    ans += sum;
  }
  std::cout << ans << "\n";
}