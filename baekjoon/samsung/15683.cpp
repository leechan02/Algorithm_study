#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int n, m, min = 1e9;
int map[9][9];
int tmp[9][9];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
struct pos{
  int which, y, x;
};
int kind[6] = {0, 4, 2, 4, 4, 1};
std::vector<pos> cctv;
std::vector<std::pair<pos, int>> com;
std::vector<std::vector<int>> one = {{0}, {1}, {2}, {3}};
std::vector<std::vector<int>> two = {{0, 2}, {1, 3}};
std::vector<std::vector<int>> three = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
std::vector<std::vector<int>> four = {{3, 0, 1}, {0, 1, 2}, {1, 2, 3}, {2, 3, 0}};
std::vector<std::vector<int>> five = {{0, 1, 2, 3}};

void check() {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (tmp[i][j] == 0) ++cnt;
    }
  }
  min = std::min(cnt, min);
}

void sight(int y, int x, std::vector<int> line) {
  for (auto i : line) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    while (ny >= 0 && ny < n && nx >= 0 && nx < m && tmp[ny][nx] != 6) {
      if (tmp[ny][nx] == 0) tmp[ny][nx] = -1;
      ny += dy[i];
      nx += dx[i];
    }
  }
}

void activate() {
  memcpy(tmp, map, sizeof(map));
  for (auto i : com) {
    pos now = i.first;
    int d = i.second;
    if (now.which == 1) {
      sight(now.y, now.x, one[d]);
    } else if (now.which == 2) {
      sight(now.y, now.x, two[d]);
    } else if (now.which == 3) {
      sight(now.y, now.x, three[d]);
    } else if (now.which == 4) {
      sight(now.y, now.x, four[d]);
    } else {
      sight(now.y, now.x, five[d]);
    }
  }
  check();
}

void combination(int depth) {
  if (depth == cctv.size()) {
    activate();
    return;
  }
  for (int i = 0; i < kind[cctv[depth].which]; ++i) {
    com.push_back({cctv[depth], i});
    combination(depth + 1);
    com.pop_back();
  }
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
      if (map[i][j] != 0 && map[i][j] != 6) {
        cctv.push_back({map[i][j], i, j});
      }
    }
  }
  combination(0);
  std::cout << min << "\n";
}