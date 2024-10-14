#include <queue>
#include <string>
#include <vector>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(vector<string> &maps, int sx, int sy, char target) {
  int N = maps.size();
  int M = maps[0].size();
  vector<vector<int>> visited(N, vector<int>(M, 0));
  queue<pair<int, int>> q;

  visited[sx][sy] = 1;
  q.push({sx, sy});

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if (maps[x][y] == target) {
      return visited[x][y] - 1;
    }

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < N && ny >= 0 && ny < M && maps[nx][ny] != 'X' &&
          !visited[nx][ny]) {
        visited[nx][ny] = visited[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }

  return -1;
}

int solution(vector<string> maps) {
  int N = maps.size();
  int M = maps[0].size();
  int sx, sy, lx, ly, ex, ey;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (maps[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (maps[i][j] == 'L') {
        lx = i;
        ly = j;
      }
      if (maps[i][j] == 'E') {
        ex = i;
        ey = j;
      }
    }
  }

  int time1 = bfs(maps, sx, sy, 'L');
  if (time1 == -1)
    return -1;

  int time2 = bfs(maps, lx, ly, 'E');
  if (time2 == -1)
    return -1;

  return time1 + time2;
}