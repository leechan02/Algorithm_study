#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int N, M, i, j;

  std::cin >> N >> M;

  int arr[N + 1];
  for (int i = 1; i <= N; ++i) {
    std::cin >> arr[i];
  }

  int S[N + 1];
  S[0] = 0;
  for (int i = 1; i <= N; ++i) {
    S[i] = S[i - 1] + arr[i];
  }

  for (int k = 1; k <= M; ++k) {
    std::cin >> i >> j;
    std::cout << S[j] - S[i - 1] << '\n';
  }
  return (0);
}