#include <iostream>
#include <algorithm>

typedef long long ll;
ll n, m, day[100004], mx, lo, hi, ans;

bool check(int mid) {

}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::cin >> day[i];
    mx = std::max(day[i], mx);
  }

  lo = mx, hi = 1000000004;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (check(mid)) {

    } else lo = mid + 1;
  }
  std::cout << ans << "\n";
}