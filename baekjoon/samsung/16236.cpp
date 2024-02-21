#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int n, sy, sx, cnt, eat, ss = 2;
int map[25][25];
int tmp[25][25];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool visited[25][25];
struct fish {
  int d, y, x;

  bool operator<(const fish &other) const {
    if (d != other.d) return d < other.d;
    if (y != other.y) return y < other.y;
    return x < other.x;
  }
};
std::vector<fish> fishes;

void nextList(int y, int x) {
  memset(visited, 0, sizeof(visited));
  memset(tmp, 0, sizeof(tmp));
  std::queue<std::pair<int, int>> q;
  tmp[y][x] = 0;
  q.push({y, x});
  visited[y][x] = true;

  while (!q.empty()) {
    y = q.front().first, x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (visited[ny][nx] == true || map[ny][nx] > ss) continue;
      tmp[ny][nx] = tmp[y][x] + 1;
      q.push({ny, nx});
      visited[ny][nx] = true;
    }
  }

  fishes.clear();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (tmp[i][j] != 0 && map[i][j] != 0 && map[i][j] < ss) {
        fishes.push_back({tmp[i][j], i, j});
      }
    }
  }
  std::sort(fishes.begin(), fishes.end());
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
      if (map[i][j] == 9) {
        sy = i, sx = j;
        map[i][j] = 0;
      }
    }
  }
  while (true) {
    nextList(sy, sx);
    if (fishes.empty()) break;
    sy = fishes[0].y, sx = fishes[0].x;
    cnt += fishes[0].d;
    map[sy][sx] = 0;
    ++eat;
    if (eat == ss) ++ss, eat = 0;
  }
  std::cout << cnt << "\n";
}