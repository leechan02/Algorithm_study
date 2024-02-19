#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

int r, c, t, cnt, a;
int map[51][51];
int tmp[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
typedef std::pair<int, int> pos;
std::vector<int> air;
std::vector<pos> micro;

void spread() {
  memset(tmp, 0, sizeof(tmp));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (map[i][j] != 0 && map[i][j] != -1) {
        int cnt = 0;
        for (int d = 0; d < 4; ++d) {
          int ny = i + dy[d];
          int nx = j + dx[d];
          if (ny < 0 || ny >= r || nx < 0 || nx >= c || map[ny][nx] == -1) continue;
          tmp[ny][nx] += map[i][j] / 5;
          ++cnt;
        }
        map[i][j] -= (map[i][j] / 5) * cnt;
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      map[i][j] += tmp[i][j];
    }
  }
}

void dust() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (map[i][j] == -1 || map[i][j] == 0) continue;
      cnt += map[i][j];
    }
  }
}

void clean() {
  for(int y = air[0] - 1; y > 0; --y) map[y][0] = map[y - 1][0];
  for (int x = 0; x < c - 1; ++x) map[0][x] = map[0][x + 1];
  for (int y = 0; y < air[0]; ++y) map[y][c - 1] = map[y + 1][c - 1];
  for (int x = c - 1; x > 1; --x) map[air[0]][x] = map[air[0]][x - 1];
  map[air[0]][1] = 0;

  for (int y = air[1] + 1; y < r - 1; ++y) map[y][0] = map[y + 1][0];
  for (int x = 0; x < c - 1; ++x) map[r - 1][x] = map[r - 1][x + 1];
  for (int y = r - 1; y > air[1]; --y) map[y][c - 1] = map[y - 1][c - 1];
  for (int x = c - 1; x > 1; --x) map[air[1]][x] = map[air[1]][x - 1];
  map[air[1]][1] = 0;
}

int main() {
  std::cin >> r >> c >> t;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cin >> map[i][j];
      if (map[i][j] == -1) air.push_back(i);
    }
  }

  while (t--) {
    spread();
    clean();
  }
  dust();
  std::cout << cnt << "\n";
}