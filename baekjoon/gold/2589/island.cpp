#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define GREEN "\033[32m"
#define RESET "\033[0m"

int n, m;
int ans = 0;
int map[51][51];
bool visited[51][51];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
typedef std::pair<int, int> pos;
std::vector<pos> start;

void BFS(int y, int x) {
  std::queue<pos> queue;
  queue.push({y, x});
  visited[y][x] = true;

  while (!queue.empty()) {
    int nowY = queue.front().first;
    int nowX = queue.front().second;
    queue.pop();

    for (int i = 0; i < 4; ++i) {
      int newY = nowY + dy[i];
      int newX = nowX + dx[i];
      if (newY >= 0 && newX >= 0 && visited[newY][newX] == false &&
          map[newY][newX] == 1) {
        map[newY][newX] = map[nowY][nowX] + 1;
        queue.push({newY, newX});
        visited[newY][newX] = true;
      }
    }
  }

  int max = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      max = std::max(max, map[y][x]);
      if (map[y][x] > 1) {
        map[y][x] = 1;
      }
    }
  }
  ans = std::max(ans, max);
}

int main() {
  std::cin >> n >> m;
  for (int y = 0; y < n; ++y) {
    std::string str;
    std::cin >> str;
    for (int x = 0; x < m; ++x) {
      if (str[x] == 'L') {
        map[y][x] = 1;
        start.push_back({y, x});
      }
    }
  }

  for (int i = 0; i < start.size(); ++i) {
    memset(visited, 0, sizeof(visited));
    BFS(start[i].first, start[i].second);
  }
  std::cout << ans - 1 << "\n";
}