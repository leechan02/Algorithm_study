#include <iostream>
#include <vector>
#include <algorithm>

int t, n, m;

int main() {
  std::cin >> t;
  while (t--) {
    int ans = 0;
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::vector<int> b(m);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < m; ++i) std::cin >> b[i];
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
      auto pos = std::lower_bound(b.begin(), b.end(), a[i]);
      ans += (int)(pos - b.begin());
    }
    std::cout << ans << "\n";
  }
}