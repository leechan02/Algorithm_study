#include <iostream>
#include <vector>
#include <cstring>

int n, m, a, b, y, x, ny, nx, my, mx, left;
int map[51][51];
bool visited[51][51];
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
std::vector<std::pair<int, int>> list;
std::vector<std::pair<int, int>> clouds;

void leftCheck() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      left += map[i][j];
    }
  }
}

void makeClouds() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map[i][j] > 1 && visited[i][j] == false) {
        clouds.push_back({i, j});
        map[i][j] -= 2;
      }
    }
  }
}

void move(int d, int c) {
  memset(visited, 0, sizeof(visited));
  std::vector<std::pair<int, int>> nextClouds;
  for (auto cloud : clouds) {
    y = cloud.first, x = cloud.second;
    for (int i = 0; i < c; ++i) {
      my = (dy[d] < 0) ? (n - 1) : dy[d];
      mx = (dx[d] < 0) ? (n - 1) : dx[d];
      y = (y + my) % n;
      x = (x + mx) % n;
    }
    map[y][x] += 1;
    visited[y][x] = true;
    nextClouds.push_back({y, x});
  }
  for (auto cloud : nextClouds) {
    y = cloud.first, x = cloud.second;
    for (int i = 1; i <= 7; i += 2) {
      ny = y + dy[i];
      nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == 0) continue;
      map[y][x] += 1;
    }
  }
  clouds.clear();
  makeClouds();
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
    }
  }
  while (m--) {
    std::cin >> a >> b;
    list.push_back({a - 1, b});
  }

  clouds.push_back({n - 1, 0});
  clouds.push_back({n - 1, 1});
  clouds.push_back({n - 2, 0});
  clouds.push_back({n - 2, 1});
  for (auto order : list) {
    move(order.first, order.second);
  }
  leftCheck();
  std::cout << left << "\n";
}