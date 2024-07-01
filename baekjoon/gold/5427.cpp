#include <iostream>
#include <queue>
#include <cstring>
#include <iostream>

struct pos{
  int y, x;
};

char tmp;
int t, w, h, res, ny, nx, min;
int map[1001][1001];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
std::queue<pos> q;

void bfs() {
  while (!q.empty()) {
    auto[cury, curx] = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      ny = cury + dy[i];
      nx = curx + dx[i];
      if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      if (map[ny][nx] == 0 || (map[ny][nx] > 0 && map[cury][curx] * -1 + 1 == map[ny][nx])) {
        if (map[cury][curx] < 0) {
          map[ny][nx] = map[cury][curx] - 1;
        } else {
          map[ny][nx] = map[cury][curx] + 1;
        }
        q.push({ny, nx});
      }
    }
  }
}

int checkExit() {
  for (int i = 0; i < w; ++i) {
    if (map[0][i] > 0) min = std::min(min, map[0][i]);
  }
  for (int i = 0; i < w; ++i) {
    if (map[h - 1][i] > 0) min = std::min(min, map[h - 1][i]);
  }
  for (int i = 0; i < h; ++i) {
    if (map[i][0] > 0) min = std::min(min, map[i][0]);
  }
  for (int i = 0; i < h; ++i) {
    if (map[i][w - 1] > 0) min = std::min(min, map[i][w - 1]);
  }

  if (min == 987654321) return 0;
  else return min;
}

int main() {
  std::cin >> t;
  while (t--) {
    std::cin >> w >> h;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        std::cin >> tmp;
        if (tmp == '.') {
          map[i][j] = 0;
        } else if (tmp == '#') {
          map[i][j] = -2;
        } else if (tmp == '@') {
          q.push({i, j});
          map[i][j] = 1;
        } else if (tmp == '*') {
          map[i][j] = -1;
          q.push({i, j});
        }
      }
    }

    bfs();

    min = 987654321;
    res = checkExit();
    if (!res) std::cout << "IMPOSSIBLE\n";
    else std::cout << res << "\n";
  }
}