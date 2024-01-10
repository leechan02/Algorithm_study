#include <iostream>
#include <vector>

int n, k;
const int INF = -987654321;

int main() {
  std::cin >> n >> k;

  std::vector<int> tem(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    std::cin >> tem[i];
  }

  std::vector<int> D(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    D[i] = D[i - 1] + tem[i];
  }

  int start = 1, end = k, max = INF, sum = 0;
  while (end <= n) {
    sum = D[end] - D[start - 1];
    if (sum > max) {
      max = sum;
    }
    ++start;
    ++end;
  }
  std::cout << max << "\n";
  return (0);
}