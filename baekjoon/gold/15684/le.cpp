#include <iostream>
#include <algorithm>

#define INF 987654321

int n, m, h;
int ans = INF;
bool visited[31][31];

bool check() {
  for (int i = 1; i <= n; ++i) {
    int start = i;
    for (int j = 1; j <= h; ++j) {
      if (visited[j][start]) ++start;
      else if (visited[j][start - 1]) --start;
    }
    if (start != i) return false;
  }
  return true;
}

void dfs(int now, int cnt) {
  if (cnt > 3 || cnt >= ans) return;
  if (check()) {
    ans = std::min(ans, cnt);
    return;
  }
  for (int i = now; i <= h; ++i) {
    for (int j = 1; j < n; ++j) {
      if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
      visited[i][j] = true;
      dfs(i, cnt + 1);
      visited[i][j] = false;
    }
  }
}

int main() {
  std::cin >> n >> m >> h;
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    visited[a][b] = true;
  }
  dfs(1, 0);
  std::cout << ((ans == INF) ? -1 : ans) << "\n";
}