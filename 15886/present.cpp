#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N;
  std::cin >> N;

  std::string road;
  std::cin >> road;

  int res = 0;
  for (int i = 0; i < N; i++) {
    if (i != 0 && road[i] == 'W' && road[i - 1] != 'W') {
      res++;
    }
  }
  std::cout << res << std::endl;
  return 0;
}