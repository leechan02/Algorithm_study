#include <iostream>
#include <queue>

char map[1004][1004];
int n, m, startY, startX, ans;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
const int INF = 987654321;
int fire[1004][1004], person[1004][1004];

int main() {
  std::queue<std::pair<int, int>> q;
  std::cin >> n >> m;
  std::fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INF);
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      std::cin >> map[y][x];
      if (map[y][x] == 'F') {
        fire[y][x] = 1;
        q.push({y, x});
      } else if (map[y][x] == 'J') {
        startY = y, startX = x;
      }
    }
  }

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int newY = y + dy[i];
      int newX = x + dx[i];
      if (newY < 0 || newY >= n || newX < 0 || newX >= m) continue;
      if (fire[newY][newX] != INF || map[newY][newX] == '#') continue;
      fire[newY][newX] = fire[y][x] + 1;
      q.push({newY, newX});
    }
  }

  person[startY][startX] = 1;
  q.push({startY, startX});
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    if (x == m - 1 || y == n - 1 || x == 0 || y == 0) {
      ans = person[y][x];
      break;
    }
    for (int i = 0; i < 4; ++i) {
      int newY = y + dy[i];
      int newX = x + dx[i];
      if (newY < 0 || newY >= n || newX < 0 || newX >= m) continue;
      if (person[newY][newX] || map[newY][newX] == '#') continue;
      if (fire[newY][newX] <= person[y][x] + 1) continue;
      person[newY][newX] = person[y][x] + 1;
      q.push({newY, newX});
    }
  }
  if (ans != 0) {
    std::cout << ans << "\n";
  } else {
    std::cout << "IMPOSSIBLE\n";
  }
}