#include <iostream>
#include <algorithm>
#include <cstring>

int n, dp[16][1 << 16], dist[16][16];

int tsp(int here, int visited) {
  if (visited == (1 << n) - 1) {
    return dist[here][0] ? dist[here][0] : 1e9;
  }

  int &ret = dp[here][visited];
  if (ret != -1) return ret;

  ret = 1e9;
  for (int i = 0; i < n; i++) {
    if (visited & (1 << i) || dist[here][i] == 0) continue;
    ret = std::min(ret, tsp(i, visited | (1 << i)) + dist[here][i]);
  }
  return ret;
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> dist[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  std::cout << tsp(0, 1) << '\n';
  return 0;
}
