#include <iostream>
#include <cstring>

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int map[51][51];
int visited[51][51];

void DFS(int y, int x) {
  visited[y][x] = 1;
  for (int i = 0; i < 4; ++i) {
    int newY = y + dy[i];
    int newX = x + dx[i];
    if (newY >= 0 && newX >= 0 && map[newY][newX] == 1 &&
        visited[newY][newX] == 0) {
      DFS(newY, newX);
    }
  }
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int m, n, k;
    std::cin >> m >> n >> k;

    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
    while (k--) {
      int x, y;
      std::cin >> x >> y;
      map[y][x] = 1;
    }
    int cnt = 0;
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < m; ++x) {
        if (map[y][x] == 1 && visited[y][x] == 0) {
          ++cnt;
          DFS(y, x);
        }
      }
    }
    std::cout << cnt << "\n";
  }
}