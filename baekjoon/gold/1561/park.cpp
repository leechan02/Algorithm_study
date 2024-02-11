#include <iostream>

typedef long long ll;
ll n, m, ans, mid, tmp;

bool check(ll mid, ll a[]) {
  tmp = m;
  for (ll i = 0; i <m; ++i) tmp += mid / a[i];
  return tmp >= n;
}

int main() {
  std::cin >> n >> m;
  ll a[m + 4];
  for (int i = 0; i < m; ++i) std::cin >> a[i];
  if (n <= m) {
    std::cout << n;
    return 0;
  }

  ll lo = 0, hi = n * 30 + 4;
  while (lo <= hi) {
    mid = (lo + hi) / (ll)(2);
    if (check(mid, a)) {
      ans = mid;
      hi = mid - 1;
    } else lo = mid + 1;
  }
  tmp = m;
  for (ll i = 0; i < m; ++i) tmp += ((ans - 1) / a[i]);

  for (ll i = 0; i < m; ++i) {
    if (ans % a[i] == 0) ++tmp;
    if (tmp == n) {
      std::cout << i + 1 << "\n";
      return 0;
    }
  }
}