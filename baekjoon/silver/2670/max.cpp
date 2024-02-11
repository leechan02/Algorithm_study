#include <iostream>
#include <algorithm>

int n;
double a[10001], ans, b;

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  double b = a[0];
  ans = b;
  for (int i = 1; i < n; ++i) {
    if (a[i] > b * a[i]) b = a[i];
    else b *= a[i];
    ans = std::max(b, ans);
  }
  printf("%.3lf", ans);
}