#include <iostream>
#include <vector>
#include <queue>

int n;
std::vector<std::pair<int, int>> v;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int pay, day;
    std::cin >> pay >> day;

    v.push_back({day, pay});
  }
  std::sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    pq.push(v[i].second);
    if (pq.size() > v[i].first) {
      pq.pop();
    }
  }
  int ans = 0;
  while (pq.size()) {
    ans += pq.top(); pq.pop();
  }
  std::cout << ans << "\n";
}