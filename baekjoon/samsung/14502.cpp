#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

int n, m, max;
int map[9][9];
int tmp[9][9];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[9][9];
std::vector<int> wall;
std::vector<std::pair<int, int>> virus;
std::vector<std::pair<int, int>> empty;


void check() {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (tmp[i][j] == 0) ++cnt;
    }
  }
  max = std::max(cnt, max);
}

void bfs(int y, int x) {
  if (visited[y][x] == true) return;
  std::queue<std::pair<int, int>> q;

  q.push({y, x});
  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    tmp[y][x] = 2;
    visited[y][x] = true;
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] == true || tmp[ny][nx] != 0) continue;
      q.push({ny, nx});
    }
  }
}

void spread() {
  memcpy(tmp, map, sizeof(map));
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < 3; ++i) {
    tmp[empty[wall[i]].first][empty[wall[i]].second] = 1;
  }
  for (auto pos : virus) {
    bfs(pos.first, pos.second);
  }
  check();
}

int cnt = 0;
void combination(int start) {
  if (wall.size() == 3) {
    spread();
    return;
  }
  for (int i = start; i < empty.size(); ++i) {
    wall.push_back(i);
    combination(i + 1);
    wall.pop_back();
  }
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
      if (map[i][j] == 0) empty.push_back({i, j});
      else if (map[i][j] == 2) virus.push_back({i, j});
    }
  }

  combination(0);
  std::cout << max << "\n";
}