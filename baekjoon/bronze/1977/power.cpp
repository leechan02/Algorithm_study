#include <iostream>
#include <vector>

std::vector<int> dp(101, 0);

int main() {
  int m, n;
  std::cin >> m >> n;

  for (int i = 0; i <= 100; ++i) {
    dp[i] = i * i;
  }

  int start = 0;
  for (int i = 1; i <= 100; ++i) {
    if (dp[i] >= m) {
      start = i;
      break;
    }
  }

  int end = 0;
  for (int i = 100; i > 0; --i) {
    if (dp[i] <= n) {
      end = i;
      break;
    }
  }

  int sum = 0;
  for (int i = start; i <= end; ++i) {
    sum += dp[i];
  }

  if (sum) {
    std::cout << sum << '\n';
    std::cout << dp[start] << '\n';
  } else {
    std::cout << "-1\n";
  }
  return (0);
}