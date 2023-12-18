#include <iostream>
#include <vector>

int main() {
  long long n;
  std::cin >> n;

  long long res = n;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      res -= res / i;
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    res -= res / n;
  }
  std::cout << res << "\n";
  return (0);
}