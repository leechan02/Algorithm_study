#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T, N, M, a, b;

  std::cin >> T;

  for (int i = 0; i < T; i++) {
    std::cin >> N >> M;
    for (int j = 0; j < M; j++) {
      std::cin >> a >> b;
    }
    std::cout << N - 1 << std::endl;
  }
  return 0;
}