#include <iostream>
#include <cstring>
#include <vector>

int n, sy, sx, ny, nx, left, total;
int map[500][500];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
struct pos {
  int y, x, p;
};
std::vector<pos> dust[4] = {{{-1, 0, 7}, {-2, 0, 2}, {1, 0, 7}, {2, 0, 2}, {-1, 1, 1}, {1, 1, 1}, {-1, -1, 10}, {1, -1, 10}, {0, -2, 5}},
                            {{0, -1, 7}, {0, -2, 2}, {0, 1, 7}, {0, 2, 2}, {-1, -1, 1}, {-1, 1, 1}, {1, -1, 10}, {1, 1, 10}, {2, 0, 5}},
                            {{-1, 0, 7}, {-2, 0, 2}, {1, 0, 7}, {2, 0, 2}, {-1, -1, 1}, {1, -1, 1}, {-1, 1, 10}, {1, 1, 10}, {0, 2, 5}},
                            {{0, -1, 7}, {0, -2, 2}, {0, 1, 7}, {0, 2, 2}, {1, -1, 1}, {1, 1, 1}, {-1, -1, 10}, {-1, 1, 10}, {-2, 0, 5}}};

void checkLeft() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map[i][j] != 0) left += map[i][j];
    }
  }
}

void spread(int i, int j, int d) {
  int now = map[i][j];
  for (auto t : dust[d]) {
    ny = i + t.y;
    nx = j + t.x;
    int wind = now * t.p / 100;
    if (ny < 0 || ny >= n || nx < 0 || nx >= n){
      map[i][j] -= wind;
      continue;
    }
    map[ny][nx] += wind;
    map[i][j] -= wind;
  }
  ny = i + dy[d];
  nx = j + dx[d];
  if (ny >= 0 && ny < n && nx >= 0 && nx < n) map[ny][nx] += map[i][j];
  map[i][j] = 0;
}

int main() {
  std::ios::sync_with_stdio(0);std::cout.tie(0);std::cin.tie(0);
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
      total += map[i][j];
    }
  }
  sy = n / 2, sx = n / 2;
  int w = 1, d = 3;
  while (!(sy == 0 && sx == 0)) {
    for (int j = 0; j < 2; ++j) {
      d = (d + 1) % 4;
      for (int i = 0; i < w; ++i) {
        sy = sy + dy[d];
        sx = sx + dx[d];
        spread(sy, sx, d);
        if (sy == 0 && sx == 0) break;
      }
      if (sy == 0 && sx == 0) break;
    }
    ++w;
  }
  checkLeft();
  std::cout << total - left << "\n";
}