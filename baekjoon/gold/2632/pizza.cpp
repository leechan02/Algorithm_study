#include <iostream>
#include <map>

int a[1001], b[1001], ans, dpa[2002], dpb[2002], size, n, m;
std::map<int, int> aCnt, bCnt;

void make(int n, int dp[], std::map<int, int> &map) {
  for (int interval = 1; interval <= n; ++interval) {
    for (int start = interval; start <= n + interval - 1; ++start) {
      int sum = dp[start] - dp[start - interval];
      map[sum]++;
      if (interval == n) break;
    }
  }
}

int main() {
  std::cin >> size >> n >> m;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    dpa[i] = dpa[i - 1] + a[i];
  }
  for (int i = n + 1; i <= 2 * n; ++i) dpa[i] = dpa[i - 1] + a[i - n];
  for (int i = 1; i <= m; ++i) {
    std::cin >> b[i];
    dpb[i] = dpb[i - 1] + b[i];
  }
  for (int i = m + 1; i <= 2 * m; ++i) dpb[i] = dpb[i - 1] + b[i - m];
  make(n, dpa, aCnt);
  make(m, dpb, bCnt);
  ans = (aCnt[size] + bCnt[size]);
  for (int i = 1; i < size; ++i) {
    ans += (aCnt[i] * bCnt[size - i]);
  }
  std::cout << ans << "\n";
}
