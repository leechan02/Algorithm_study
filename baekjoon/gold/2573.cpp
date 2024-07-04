#include <iostream>
#include <queue>
#include <cstring>

struct pos{
  int y, x;
};

int n, m, t, ny, nx, zero;
int map[301][301];
int tmp[301][301];
bool visited[301][301];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};


void melt() {
  memset(tmp, 0, sizeof(tmp));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i][j] == 0) continue;
      zero = 0;
      for (int k = 0; k < 4; ++k) {
        ny = i + dy[k];
        nx = j + dx[k];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] != 0) continue;
        ++zero;
      }
      tmp[i][j] = zero;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i][j] == 0) continue;
      map[i][j] -= tmp[i][j];
      if (map[i][j] < 0) map[i][j] = 0;
    }
  }
}

void bfs(int y, int x) {
  std::queue<pos> q;
  q.push({y, x});
  visited[y][x] = true;

  while (!q.empty()) {
    pos cur = q.front(); q.pop();

    for (int i = 0; i < 4; ++i) {
      ny = cur.y + dy[i];
      nx = cur.x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] == true || map[ny][nx] < 1) continue;
      visited[ny][nx] = true;
      q.push({ny, nx});
    }
  }
}

int checkIsland() {
  int island = 0;

  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i][j] < 1 || visited[i][j]) continue;
      bfs(i, j);
      ++island;
    }
  }

  if (island > 1) {
    std::cout << t << "\n";
    return false;
  } else if (island == 0) {
    std::cout << "0\n";
    return false;
  }
  return true;
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++ j) {
      std::cin >> map[i][j];
    }
  }

  do {
    melt();
    ++t;
  } while (checkIsland());
}