#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

struct pos {
  int y, x, wall; // wall: 벽을 부쉈는지 여부
};

int n, m;
int map[1001][1001];
int dist[1001][1001][2]; // dist[y][x][0]: 벽을 부수지 않고 도달한 거리,
                         // dist[y][x][1]: 벽을 부수고 도달한 거리
std::string tmp;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int bfs() {
  std::queue<pos> q;
  q.push({0, 0, 0});
  dist[0][0][0] = 1;

  while (!q.empty()) {
    pos cur = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];
      int wall = cur.wall;

      if (ny < 0 || ny >= n || nx < 0 || nx >= m)
        continue;

      // 벽을 부수지 않고 이동하는 경우
      if (map[ny][nx] == 0 && dist[ny][nx][wall] == 0) {
        dist[ny][nx][wall] = dist[cur.y][cur.x][wall] + 1;
        q.push({ny, nx, wall});
      }
      // 벽을 부수고 이동하는 경우
      if (wall == 0 && map[ny][nx] == -1 && dist[ny][nx][1] == 0) {
        dist[ny][nx][1] = dist[cur.y][cur.x][wall] + 1;
        q.push({ny, nx, 1});
      }
    }
  }

  if (dist[n - 1][m - 1][0] != 0 && dist[n - 1][m - 1][1] != 0) {
    return std::min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
  } else if (dist[n - 1][m - 1][0] != 0) {
    return dist[n - 1][m - 1][0];
  } else if (dist[n - 1][m - 1][1] != 0) {
    return dist[n - 1][m - 1][1];
  } else {
    return -1;
  }
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;
    for (int j = 0; j < m; ++j) {
      if (tmp[j] == '1') {
        map[i][j] = -1;
      } else {
        map[i][j] = 0;
      }
    }
  }

  int result = bfs();
  if (result != -1) {
    std::cout << result << "\n";
  } else {
    std::cout << "-1\n";
  }
}