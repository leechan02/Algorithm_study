#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<long long, long long>> v(n);
  std::vector<long long> vv(k);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i].first >> v[i].second;
  }
  for (int i = 0; i < k; ++i) {
    std::cin >> vv[i];
  }
  std::sort(v.begin(), v.end());
  std::sort(vv.begin(), vv.end());
  std::priority_queue<long long> pq;

  int i = 0, ans = 0;
  for (int j = 0; j < k; ++j) {
    while (i < n && v[i].first <= vv[i]) {
      pq.push(v[i].second);
      ++i;
    }
    if (pq.size()) {
      ans += pq.top();
      pq.pop();
    }
  }
  std::cout << ans << "\n";
}