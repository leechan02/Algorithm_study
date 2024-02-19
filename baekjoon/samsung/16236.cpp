#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>

int n, sy, sx, y, x, ny, nx, cnt, eat, ss = 2;
int map[21][21];
int tmp[21][21];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool visited[21][21];
struct fish{
  int s, y, x;
};
std::deque<fish> fishes;

bool com(fish &a, fish &b) {
  int al = abs(sy - a.y) + abs(sx - a.x);
  int bl = abs(sy - b.y) + abs(sx - b.x);
  if (a.s > b.s) return false;
  else if (a.s == b.s && al > bl) return false;
  else if (a.s == b.s && al == bl && a.y > b.y) return false;
  else if (a.s == b.s && al == bl && a.y == b.y && a.x > b.x) return false;
  return true;
}

void print() {
  std::cout << "\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << tmp[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int go(int ty, int tx) {
  memset(tmp, 0, sizeof(tmp));
  memset(visited, 0, sizeof(visited));
  std::queue<std::pair<int, int>> q;
  map[sy][sx] = 0;
  q.push({sy, sx});
  visited[sy][sx] = true;
  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      ny = y + dy[i];
      nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] == true || map[ny][nx] > ss) continue;
      tmp[ny][nx] = tmp[y][x] + 1;
      visited[ny][nx] = true;
      q.push({ny, nx});
    }
  }
  // print();
  return tmp[ty][tx];
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
      if (map[i][j] == 9) sy = i, sx = j;
      else if (map[i][j] != 0) fishes.push_back({map[i][j], i, j});
    }
  }
  // for (auto t : fishes) {
  //   std::cout << t.s << " " << t.y << " " << t.x << "\n";
  // }
  while (!fishes.empty()) {
    std::sort(fishes.begin(), fishes.end(), com);
    int ts = fishes.front().s, ty = fishes.front().y, tx = fishes.front().x;
    // std::cout << "t: " << ts << " " << ty << " " << tx << "\n";
    if (ts >= ss || go(ty, tx) == 0) break;
    cnt += tmp[ty][tx];
    ++eat;
    if (eat == ss) ++ss, eat = 0;
    sy = ty, sx = tx;
    fishes.pop_front();
  }
  std::cout << cnt << "\n";
}