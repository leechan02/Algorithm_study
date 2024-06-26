#include <iostream>
#include <vector>
#include <algorithm>

int n,m, max, num, nx, ny, size;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char map[501][501];
bool visited[501][501];

void dfs(int y, int x) {
  visited[y][x] = true;
  ++size;
  for (int i = 0; i < 4; ++i) {
    ny = y + dy[i];
    nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] == true || map[ny][nx] != '1') continue;
    dfs(ny, nx);
  }
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (visited[i][j] == false && map[i][j] == '1') {
        size = 0;
        dfs(i, j);
        max = std::max(max, size);
        ++num;
      }
    }
  }

  std::cout << num << "\n" << max << "\n";
}