#include <algorithm>
#include <iostream>

const int INF = 1000000;

int main() {
  int n, m;
  std::cin >> n >> m;

  int D[n + 1][n + 1];

  for (int s = 1; s <= n; ++s) {
    for (int e = 1; e <= n; ++e) {
      if (s == e) {
        D[s][e] = 0;
      } else {
        D[s][e] = INF;
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    D[a][b] = 1;
    D[b][a] = 1;
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        D[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);
      }
    }
  }

  int minKevinBacon = INF;
  int person = 0;

  for (int i = 1; i <= n; ++i) {
    int kevinBacon = 0;
    for (int j = 1; j <= n; ++j) {
      kevinBacon += D[i][j];
    }
    if (kevinBacon < minKevinBacon) {
      minKevinBacon = kevinBacon;
      person = i;
    }
  }

  std::cout << person << std::endl;
  return 0;
}
