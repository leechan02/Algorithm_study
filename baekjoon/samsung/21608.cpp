#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

int n, m, f, score;
int map[21][21];
int love[21][21];
int nothing[21][21];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
std::vector<std::vector<int>> list(404, (std::vector<int>(4, 0)));
std::vector<std::pair<int, int>> chairs;

bool findLove(int me) {
  chairs.clear();
  memset(love, 0, sizeof(love));
  int mx = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      if (map[y][x] != 0) continue;
      int cnt = 0;
      for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == 0) continue;
        auto it = find(list[me].begin(), list[me].end(), map[ny][nx]);
        if (it != list[me].end()) ++cnt;
      }
      love[y][x] = cnt;
      mx = std::max(mx, cnt);
    }
  }

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      if (map[y][x] == 0 && love[y][x] == mx) chairs.push_back({y, x});
    }
  }
  if (chairs.size() == 1) {
    map[chairs[0].first][chairs[0].second] = me;
    return true;
  }
  return false;
}

void sitting(int student) {
  if (findLove(student)) return;
  memset(nothing, 0, sizeof(nothing));
  int mx = 0;
  for (auto chair : chairs) {
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
      int ny = chair.first + dy[i];
      int nx = chair.second + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] != 0) continue;
      ++cnt;
    }
    nothing[chair.first][chair.second] = cnt;
    mx = std::max(mx, cnt);
  }

  for (auto chair : chairs) {
    if (nothing[chair.first][chair.second] == mx) {
      map[chair.first][chair.second] = student;
      return;
    }
  }
}

void getScore() {
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      int cnt = 0;
      for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        auto it = find(list[map[y][x]].begin(), list[map[y][x]].end(), map[ny][nx]);
        if (it != list[map[y][x]].end()) ++cnt;
      }
      if (cnt == 1) score += 1;
      else if (cnt == 2) score += 10;
      else if (cnt == 3) score += 100;
      else if (cnt == 4) score += 1000;
    }
  }
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n * n; ++i) {
    std::cin >> m;
    for (int j = 0; j < 4; ++j) {
      std::cin >> f;
      list[m][j] = f;
    }
    sitting(m);
  }
  getScore();
  std::cout << score << "\n";
}