#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

int n, l, r, cnt, total;
int map[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool tmp[51][51];
bool visited[51][51];
typedef std::pair<int, int> pos;
std::vector<pos> change;

void move() {
  if (change.size() == 1) return;
  ++cnt;
  for (auto i : change) {
    map[i.first][i.second] = total / change.size();
  }
}

void bfs(int y, int x) {
  memset(tmp, 0, sizeof(tmp));
  std::queue<pos> q;
  q.push({y, x});

  total = 0;
  while (!q.empty()){
    y = q.front().first;
    x = q.front().second;
    q.pop();

    total += map[y][x];
    tmp[y][x] = true;
    change.push_back({y, x});
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 1 || ny > n || nx < 1 || nx > n || tmp[ny][nx] == true) continue;
      if (abs(map[ny][nx] - map[y][x]) < l || abs(map[ny][nx] - map[y][x]) > r) continue;
      q.push({ny, nx});
    }
  }
  move();
  change.clear();
}

void print() {
  std::cout << "\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cout << map[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  std::cin >> n >> l >> r;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cin >> map[i][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      bfs(i, j);
    }
  }
  std::cout << cnt << "\n";
}