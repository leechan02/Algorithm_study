#include <iostream>
#include <vector>
#include <algorithm>

int n, t, max, tmpIdx;
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
    if (f.idx == 0) continue;
    y = f.y;
    x = f.x;

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
    if (map[ny][nx] != 0) {
      fishes[map[ny][nx] - 1].y = y, fishes[map[ny][nx] - 1].x = x;
    }
    fishes[map[y][x] - 1].y = ny, fishes[map[y][x] - 1].x = nx, fishes[map[y][x] - 1].dir = i;
    std::swap(map[y][x], map[ny][nx]);
  }
}

void moveShark(int y, int x, int sum, int d) {
  max = std::max(sum, max);
  moveFishes();
  int tmpFish;
  for (int i = 1; i <= 4; ++i) {
    int ny = y + dy[d] * i;
    int nx = x + dx[d] * i;
    if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || map[ny][nx] == 0) return;
    tmpFish = map[ny][nx];
    map[y][x] = 0;
    map[ny][nx] = -1;
    fishes[tmpFish - 1].idx = 0;
    moveShark(ny, nx, sum + tmpFish, fishes[tmpFish - 1].dir);
    fishes[tmpFish - 1].idx = tmpFish;
    map[ny][nx] = tmpFish;
    map[y][x] = -1;
  }
}

int main() {
  int shark, sharkDir;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cin >> n >> t;
      map[i][j] = n;
      fishes.push_back({n, t - 1, i, j});
      if (i == 0 && j == 0) shark = n, sharkDir = t;
    }
  }
  std::sort(fishes.begin(), fishes.end());
  fishes[map[0][0] - 1].idx = 0;
  map[0][0] = -1;
  moveShark(0, 0, shark, sharkDir);
  std::cout << max << "\n";
}