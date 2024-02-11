#include <iostream>
#include <vector>
#include <algorithm>

int t, n, m;

int main() {
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    std::cin >> m;
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) std::cin >> b[i];
    std::sort(a.begin(), a.end());

    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      auto pos = std::lower_bound(a.begin(), a.end(), b[i]);
      if (pos != a.end() && *pos == b[i]) {
        std::cout << "1\n";
      } else {
        std::cout << "0\n";
      }
    }
  }
}