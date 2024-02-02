#include <iostream>
#include <queue>

char map[301][301];
typedef std::pair<int, int> pos;
int visited[301][301];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};


int main() {
  int n, m, x1, y1, x2, y2;
  std::cin >> n >> m >> x1 >> y1 >> x2 >> y2;

  for (int i = 1; i <= n; ++i) {
    std::cin >> map[i];
  }
}