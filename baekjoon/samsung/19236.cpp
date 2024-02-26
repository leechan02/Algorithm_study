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

void print() {
  std::cout << "\n";
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cout << map[i][j] << " ";
    }
    std::cout << "\n";
  }
}

void moveFishes() {
  int y, x, ny, nx, ty, tx, i;
  for (auto f : fishes) {
    y = f.y;
    x = f.x;

    std::cout << "\n" << "before: " << f.idx;
    i = f.dir;
    do {
      ny = y + dy[i];
      nx = x + dx[i];
      if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || map[ny][nx] == -1) {
        i = (i + 1) % 8;
        continue;
      }
      break;
    } while (i != f.dir);
    if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || map[ny][nx] == -1) continue;
    fishes[map[ny][nx] - 2].y = y, fishes[map[ny][nx] - 2].x = x;
    fishes[map[y][x] - 2].y = ny, fishes[map[y][x] - 2].x = nx, fishes[map[y][x] - 2].dir = i;
    std::cout << "\n" << "b: " << y << " " << x << " n: " << ny << " " << nx << " idx: " << map[y][x];
    std::swap(map[y][x], map[ny][nx]);
    print();
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