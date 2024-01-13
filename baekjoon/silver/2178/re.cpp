#include <iostream>
#include <queue>
#include <vector>

typedef std::pair<int, int> position;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int miro[101][101];
int visited[101][101];

void BFS(position start) {
  std::queue<position> queue;
  queue.push(start);

  visited[1][1] = true;
  while (!queue.empty()) {
    position now = queue.front();
    queue.pop();
    int nowX = now.first;
    int nowY = now.second;
    for (int i = 0; i < 4; ++i) {
      int newX = nowX + dx[i];
      int newY = nowY + dy[i];
      if (visited[newX][newY] == false && miro[newX][newY] != 0) {
        miro[newX][newY] = miro[nowX][nowY] + 1;
        visited[newX][newY] = true;
        queue.push({newX, newY});
      }
    }
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    std::string tmp;
    std::cin >> tmp;
    for (int j = 0; j < tmp.size(); ++j) {
      miro[i][j + 1] = tmp[j] - 48;
    }
  }

  BFS({1, 1});
  std::cout << miro[n][m] << "\n";
}