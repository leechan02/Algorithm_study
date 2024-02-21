#include <iostream>
#include <vector>
#include <cstring>

int n, m, k, s;
char map[101][101];
char tmp[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
struct tree {
  int y, x, s;
};
std::vector<tree> cross;

void checkCross(int y, int x) {
  memset(tmp, 0, sizeof(tmp));
  tmp[y][x] = '#';
  s = 1;
  while (true) {
    for (int i = 0; i < 4; ++i) {
      int ny = y;
      int nx = x;
      for (int t = 0; t < s; ++t) {
        ny += dy[i];
        nx += dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == '.') return;
        tmp[ny][nx] = '#';
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (tmp[i][j] == '#') map[i][j] = tmp[i][j];
      }
    }
    cross.push_back({y, x, s});
    ++k;
    ++s;
  }
}

bool isFill() {
  if (k == 0) return false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i][j] == '*') return false;
    }
  }
  return true;
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
      if (map[i][j] != '.') {
        checkCross(i, j);
      }
    }
  }
  if (isFill()) {
    std::cout << k << "\n";
    for (auto t : cross) {
      std::cout << t.y + 1 << " " << t.x + 1 << " " << t.s << "\n";
    }
  } else {
    std::cout << "-1\n";
  }
}