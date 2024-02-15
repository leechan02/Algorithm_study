#include <iostream>
#include <queue>

int n, m, y, x, d, cnt;
int dy[4] = {-1, 0, 1, 0}; //north, east, south, west
int dx[4] = {0, 1, 0, -1};
int map[51][51];
bool visited[51][51];
std::queue<std::pair<int, int>> q;

void clean(int sy, int sx) {
  visited[sy][sx] = true;
  q.push({sy, sx});

  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    if (map[y][x] == 0) {
      ++cnt;
      map[y][x] = 2;
    }
    int flag = 0;
    for (int i = 0; i < 4; ++i) {
      d = (d + 3) % 4;
      int ny = y + dy[d];
      int nx = x + dx[d];
      if (map[ny][nx] == 1) continue;
      else if (map[ny][nx] == 0) {
        q.push({ny, nx});
        flag = 1;
        break;
      }
    }
    if (flag) continue;
    int by = y - dy[d];
    int bx = x - dx[d];
    if (map[by][bx] == 1) return;
    q.push({by, bx});
  }
}

int main() {
  std::cin >> n >> m >> y >> x >> d;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
    }
  }
  clean(y, x);
  std::cout << cnt << "\n";
}
