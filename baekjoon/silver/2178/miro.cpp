#include <iostream>
#include <queue>

static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};
static int miro[101][101];
static bool visited[101][101];
static int N,M;

void BFS(int i, int j) {
  std::queue<std::pair<int, int> > queue;
  queue.push(std::make_pair(i, j));

  while(!queue.empty()) {
    int now[2];
    now[0] = queue.front().first;
    now[1] = queue.front().second;
    queue.pop();
    visited[i][j] = true;

    for (int k = 0; k < 4; ++k) {
      int x = now[0] + dx[k];
      int y = now[1] + dy[k];

      if (x >= 0 && y >= 0 && x < N && y < M) {
        if (miro[x][y] != 0 && !visited[x][y]) {
          visited[x][y] = true;
          miro[x][y] = miro[now[0]][now[1]] + 1;
          queue.push(std::make_pair(x, y));
        }
      }
    }
  }
}

int main() {
  std::cin >> N >> M;

  std::string tmp;
  for (int i = 0; i < N; ++i) {
    std::cin >> tmp;
    for (int j = 0; j < M; ++j) {
      miro[i][j] = tmp[j] - '0';
    }
  }

  BFS(0, 0);
  std::cout << miro[N - 1][M - 1] << '\n';
  return (0);
}