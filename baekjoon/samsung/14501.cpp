#include <iostream>
#include <algorithm>
#include <vector>

int n, t, p, max, sum;
std::vector<std::pair<int, int>> day;

void dfs(int from, int sum) {
  if (from > n) return;

  max = std::max(sum, max);
  for (int i = from; i < n; ++i) {
    dfs(i + day[i].first, sum + day[i].second);
  }
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n ; ++i) {
    std::cin >> t >> p;
    day.push_back({t, p});
  }
  dfs(0, 0);
  std::cout << max << "\n";
}