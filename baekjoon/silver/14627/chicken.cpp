#include <iostream>

typedef long long ll;
ll s, c, pa[1000004], ans, sum;

bool check(ll mid) {
  ll cnt = 0;
  for (int i = 0; i < s; ++i) cnt += pa[i] / mid;
  return cnt >= c;
}

int main() {
  std::cin >> s >> c;
  for (int i = 0; i < s; ++i) {
    std::cin >> pa[i];
    sum += pa[i];
  }

  ll lo = 1, hi = 1e9;
  while (lo <= hi) {
    ll mid = (lo + hi) / (ll)(2);
    if (check(mid)) {
      lo = mid + 1;
      ans = mid;
    } else hi = mid - 1;
  }
  std::cout << sum - ans * c << "\n";
}