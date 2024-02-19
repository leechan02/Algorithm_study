#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

int n, l, r, cnt, total, flag;
int map[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool visited[51][51];
typedef std::pair<int, int> pos;
std::vector<pos> change;

void move() {
  if (change.size() == 1) return;
  flag = 1;
  for (auto i : change) {
    map[i.first][i.second] = total / change.size();
  }
}

void bfs(int y, int x) {
  std::queue<pos> q;
  q.push({y, x});
  change.push_back({y, x});

  total = map[y][x];
  visited[y][x] = true;
  while (!q.empty()){
    y = q.front().first;
    x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] == true) continue;
      if (abs(map[ny][nx] - map[y][x]) < l || abs(map[ny][nx] - map[y][x]) > r) continue;
      total += map[ny][nx];
      visited[ny][nx] = true;
      q.push({ny, nx});
      change.push_back({ny, nx});
    }
  }
  move();
  change.clear();
}

int main() {
  std::cin >> n >> l >> r;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
    }
  }

  while (true) {
    flag = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (visited[i][j] == true) continue;
        bfs(i, j);
      }
    }
    if (flag == 0) break;
    else ++cnt;
  }
  std::cout << cnt << "\n";
}