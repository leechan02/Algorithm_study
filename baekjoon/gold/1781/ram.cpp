#include <iostream>
#include <queue>
#include <vector>

int n;
std::vector<std::pair<int, int>> v;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int dead, ramen;
    std::cin >> dead >> ramen;

    v.push_back({dead, ramen});
  }
  std::sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    pq.push(v[i].second);
    if (pq.size() > v[i].first ) {
      pq.pop();
    }
  }
  int sum = 0;
  while (!pq.empty()) {
    sum += pq.top();
    pq.pop();
  }
  std::cout << sum << "\n";
}