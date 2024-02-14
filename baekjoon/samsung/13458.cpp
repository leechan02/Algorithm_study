#include <iostream>
#include <vector>

int n, b, c;

int main() {
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::cin >> b >> c;

  long long ans = n;
  for (int i = 0; i < n; ++i) {
    a[i] -= b;
    if (a[i] < 1) continue;
    ans += (a[i] / c) + ((a[i] % c == 0) ? 0 : 1);
  }
  std::cout << ans << "\n";
}