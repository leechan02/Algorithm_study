#include <iostream>

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;

    int cnt = 0;
    for (int i = 5; i <= n; i *= 5) {
      cnt += n / i;
    }
    std::cout << cnt << "\n";
  }
}