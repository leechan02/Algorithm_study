#include <iostream>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  long long N, M, tmp;
  std::cin >> N >> M;

  long long dp[N + 1];
  long long remain[M + 1];

  for (long long i = 0; i <= M; ++i) {
    remain[i] = 0;
  }

  dp[0] = 0;
  for (long long i = 1; i <= N; ++i) {
    std::cin >> tmp;
    dp[i] = (dp[i - 1] + (tmp % M)) % M;
  }

  long long num = 0;
  for (long long i = 1; i <= N; ++i) {
    if (dp[i] == 0) {
      ++num;
    }
    remain[dp[i]]++;
  }

  for (long long i = 0; i < M; ++i) {
    num += (remain[i] * (remain[i] - 1) / 2);
  }

  std::cout << num << '\n';
  return (0);
}