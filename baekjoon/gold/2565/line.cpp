#include <iostream>
#include <vector>
#include <algorithm>

int n, a, b, len, lis[504];
std::vector<std::pair<int, int>> v;

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a >> b;
    v.push_back({a, b});
  }
  std::sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i) {
    auto it = std::lower_bound(lis, lis + len, v[i].second);
    if (*it == 0) ++len;
    *it = v[i].second;
  }
  std::cout << n - len << "\n";
}