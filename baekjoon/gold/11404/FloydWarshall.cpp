#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;

  int dist[n + 1][n + 1];
  for (int s = 1; s <= n; ++s) {
    for (int e = 1; e <= n; ++e) {
      if (s == e) {
        dist[s][e] = 0;
      } else {
        dist[s][e] = 10000001;
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (dist[a][b] > c) {
      dist[a][b] = c;
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int s = 1; s <= n; ++s) {
      for (int e = 1; e <=n; ++e) {
        dist[s][e] = std::min(dist[s][e], dist[s][k] + dist[k][e]);
      }
    }
  }

  for (int s = 1; s <= n; ++s) {
    for (int e = 1; e <= n; ++e) {
      if (dist[s][e] == 10000001) {
        std::cout << "0" << " ";
      } else {
        std::cout << dist[s][e] << " ";
      }
    }
    std::cout << "\n";
  }

  return (0);
}