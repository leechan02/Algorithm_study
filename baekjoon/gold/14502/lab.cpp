#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int n, m;
int map[9][9];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
typedef std::pair<int, int> pos;
std::vector<pos> virus;
std::vector<pos> wall;

int count() {
  bool visited[9][9] = {
      0,
  };

  std::queue<pos> queue;
  for (int i = 0; i < virus.size(); ++i) {
    int startY = virus[i].first;
    int startX = virus[i].second;
    if (visited[startY][startX] == true) {
      continue;
    }
    queue.push({startY, startX});
    visited[startY][startX] = true;
    while (!queue.empty()) {
      int nowY = queue.front().first;
      int nowX = queue.front().second;
      queue.pop();
      for (int i = 0; i < 4; ++i) {
        int newY = nowY + dy[i];
        int newX = nowX + dx[i];
        if (newX >= 0 && newY >= 0 && newX < m && newY < n &&
            visited[newY][newX] == false && map[newY][newX] != 1) {
          queue.push({newY, newX});
          visited[newY][newX] = true;
          if (map[newY][newX] == 0) {
            map[newY][newX] = 3;
          }
        }
      }
    }
  }

  int res = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      if (map[y][x] == 0) {
        ++res;
      } else if (map[y][x] == 3) {
        map[y][x] = 0;
      }
    }
  }
  return res;
}

int main() {
  std::cin >> n >> m;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      int tmp;
      std::cin >> tmp;
      map[y][x] = tmp;
      if (tmp == 2) {
        virus.push_back({y, x});
      } else if (tmp == 0) {
        wall.push_back({y, x});
      }
    }
  }

  int max = 0;
  for (int i = 0; i < wall.size(); ++i) {
    for (int j = i + 1; j < wall.size(); ++j) {
      for (int k = j + 1; k < wall.size(); ++k) {
        map[wall[i].first][wall[i].second] = 1;
        map[wall[j].first][wall[j].second] = 1;
        map[wall[k].first][wall[k].second] = 1;
        max = std::max(max, count());
        map[wall[i].first][wall[i].second] = 0;
        map[wall[j].first][wall[j].second] = 0;
        map[wall[k].first][wall[k].second] = 0;
      }
    }
  }
  std::cout << max << "\n";
}