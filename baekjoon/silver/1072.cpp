#include <iostream>

typedef long long ll;
ll a, b, mid, ans = -1;

int main() {
  std::cin >> a >> b;
  ll z = b * 100 / a;
  ll lo = 1, hi = 1e9;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if ((b + mid) * 100 / (a + mid) > z) {
      ans = mid;
      hi = mid - 1;
    } else lo = mid + 1;
  }
  std::cout << ans << "\n";
}