#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int map[101][101];
bool visited[101][101];
int n, m;
typedef std::pair<int, int> pos;

void melt(int y, int x) {
  std::queue<pos> queue;
  queue.push({y, x});

  while (!queue.empty()) {
    int nowY = queue.front().first;
    int nowX = queue.front().second;
    queue.pop();

    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
      int newY = nowY + dy[i];
      int newX = nowX + dx[i];
      if (newY >= 0 && newX >= 0 && newY < n && newX < m &&
          map[newY][newX] == -1) {
        map[nowY][nowX] = 2;
        ++cnt;
      }
    }
    for (int i = 0; i < 4; ++i) {
      int newY = nowY + dy[i];
      int newX = nowX + dx[i];
      if (newY >= 0 && newX >= 0 && newY < n && newX < m &&
          visited[newY][newX] == false && map[newY][newX] == 1 && cnt > 0) {
        queue.push({newY, newX});
        visited[newY][newX] = true;
      }
    }
  }
}

void air(int y, int x) {
  map[y][x] = -1;
  visited[y][x] = true;
  for (int i = 0; i < 4; ++i) {
    int newY = y + dy[i];
    int newX = x + dx[i];
    if (newY >= 0 && newY < n && newX >= 0 && newX < m &&
        visited[newY][newX] == false && map[newY][newX] != 1) {
      air(newY, newX);
    }
  }
}

int main() {
  std::cin >> n >> m;
  std::vector<pos> cheese;
  int hour = 0, cnt = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      int tmp;
      std::cin >> tmp;
      map[y][x] = tmp;
      if (tmp == 1) {
        cheese.push_back({y, x});
        ++cnt;
      }
    }
  }

  while (!cheese.empty()) {
    air(0, 0);
    for (int i = 0; i < cheese.size(); ++i) {
      memset(visited, 0, sizeof(visited));
      if (visited[cheese[i].first][cheese[i].second] == true) {
        continue;
      }
      visited[cheese[i].first][cheese[i].second] = true;
      melt(cheese[i].first, cheese[i].second);
    }
    cheese.clear();
    ++hour;
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < m; ++x) {
        if (map[y][x] == 2) {
          map[y][x] = -1;
        }
      }
    }

    int left = 0;
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < m; ++x) {
        if (map[y][x] == 1) {
          cheese.push_back({y, x});
          ++left;
        }
      }
    }
    if (left != 0) {
      cnt = left;
    }
  }

  std::cout << hour << "\n";
  std::cout << cnt << "\n";
}