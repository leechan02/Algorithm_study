#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct pos{
  int z, y, x;
};

int m, n, h, max;
int map[101][101][101];
std::vector<pos> dir = {{1, 0, 0}, {-1, 0, 0}, {0, 0, -1}, {0, 0, 1}, {0, 1, 0}, {0, -1, 0}};
std::queue<pos> tomato;

void bfs() {
  while (!tomato.empty()) {
    pos cur = tomato.front();
    tomato.pop();

    for (auto d : dir) {
      int nz = cur.z + d.z;
      int ny = cur.y + d.y;
      int nx = cur.x + d.x;
      if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (map[nz][ny][nx] == 0) {
        map[nz][ny][nx] = map[cur.z][cur.y][cur.x] + 1;
        tomato.push({nz, ny, nx});
      }
    }
  }
}

bool checkZero() {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        if (map[i][j][k] == 0) return true;
      }
    }
  }
  return false;
}

int main() {
  std::cin >> m >> n >> h;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        std::cin >> map[i][j][k];
        if (map[i][j][k] == 1) tomato.push({i, j, k});
      }
    }
  }

  bfs();

  if (checkZero()) {
    std::cout << "-1\n";
  } else {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < m; ++k) {
          max = std::max(max, map[i][j][k]);
        }
      }
    }

    if (max == 1) std::cout << "0\n";
    else std::cout << max - 1 << "\n";
  }
}