#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  int map[n][m];
  for (int i = 0; i < n; ++i) {
    for (int ii = 0; ii < m; ++ii) {
      std::cin >> map[i][ii];
    }
  }
}