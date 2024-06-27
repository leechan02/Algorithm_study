#include <iostream>
#include <queue>
#include <algorithm>

struct position{
  int y, x;
};

int m, n, max, ny, nx, y, x;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int map[1001][1001];
std::queue<position> tomato;

void bfs() {
  while (!tomato.empty()) {
    y = tomato.front().y;
    x = tomato.front().x;
    tomato.pop();

    for (int i = 0; i < 4; ++i) {
      ny = y + dy[i];
      nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (map[ny][nx] == 0) {
        map[ny][nx] = map[y][x] + 1;
        tomato.push({ny, nx});
      }
    }
  }
}

bool checkZero() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i][j] == 0) return true;
    }
  }
  return false;
}

int main() {
  std::cin >> m >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
      if (map[i][j] == 1) {
        tomato.push({i, j});
      }
    }
  }

  bfs();

  if (checkZero()) {
    std::cout << "-1\n";
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        max = std::max(max, map[i][j]);
      }
    }
    std::cout << max - 1 << "\n";
  }
}