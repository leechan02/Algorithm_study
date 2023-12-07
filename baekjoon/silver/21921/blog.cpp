#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, X;
  std::cin >> N >> X;

  std::vector<int> days(N, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> days[i];
  }

  int max = 0, start = 0, tmp = 0, count = 1;
  for (int i = 0; i < X; ++i) {
    max += days[i];
  }

  tmp = max;
  for (int i = start; i < N - X; ++i) {
    tmp = tmp - days[i] + days[i + X];
    if (tmp > max) {
      max = tmp;
      count = 0;
    }
    if (tmp == max) {
      count++;
    }
  }

  if (max != 0) {
    std::cout << max << '\n';
    std::cout << count << '\n';
  } else {
    std::cout << "SAD" << '\n';
  }
  return (0);
}