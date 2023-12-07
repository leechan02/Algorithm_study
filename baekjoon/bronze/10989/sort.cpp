#include <iostream>
#include <vector>

std::vector<int> count;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, tmp;
  std::cin >> N;

  count = std::vector<int>(10001, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> tmp;
    count[tmp]++;
  }

  for (int i = 1; i < 10001; ++i) {
    if (count[i] != 0) {
      for (int j = 0; j < count[i]; ++j) {
        std::cout << i << "\n";
      }
    }
  }
  return (0);
}