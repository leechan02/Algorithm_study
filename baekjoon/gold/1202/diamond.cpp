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

  int dia = 0;
  long long ans = 0;
  for (int bag = 0; bag < k; ++bag) {
    while (dia < n && v[dia].first <= vv[bag]) {
      pq.push(v[dia].second);
      ++dia;
    }
    if (pq.size()) {
      ans += pq.top();
      pq.pop();
    }
  }
  std::cout << ans << "\n";
}