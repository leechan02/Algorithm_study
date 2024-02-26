#include <iostream>
#include <vector>
#include <algorithm>

int n, t, max;
struct fish{
  int idx, dir, y, x;

  bool operator<(const fish& other) const {
    return idx < other.idx;
  }
};
int map[4][4];
std::vector<fish> fishes;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void moveFishes() {
  int y, x, ny, nx, ty, tx, td, i;
  for (auto f : fishes) {
    y = f.y;
    x = f.x;

    for (i = f.dir; i != (f.dir + 7) % 8; i = (i + 1) % 8) {
      ny = y + dy[i];
      nx = x + dx[i];
      if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || map[ny][nx] == -1) continue;
      break;
    }
    if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || map[ny][nx] == -1) continue;
    ty = fishes[map[ny][nx] - 2].y;
    tx = fishes[map[ny][nx] - 2].x;
    td = fishes[map[ny][nx] - 2].dir;
    std::swap(map[y][x], map[ny][nx]);
  }
}

void moveShark(int y, int x, int sum, int d) {
  if (y < 0 || y >= 4 || x < 0 || x >= 4) {
    max = std::max(sum, max);
    return ;
  }
  moveFishes();
}

int main() {
  int shark, sharkDir;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cin >> n >> t;
      map[i][j] = n;
      if (!(i == 0 && j == 0)) fishes.push_back({n, t - 1, i, j});
      else shark = n, sharkDir = t;
    }
  }
  map[0][0] = -1;
  std::sort(fishes.begin(), fishes.end());
  moveShark(0, 0, shark, sharkDir);
  std::cout << max << "\n";
}