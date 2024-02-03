#include <iostream>

int r, c, k, ans;
char map[6][6];
int visited[6][6];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int cnt) {
  if (y == 0 && x == c - 1 && cnt == k) {
    ++ans;
    return;
  }
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny >= 0 && ny < r && nx >= 0 && nx < c && visited[ny][nx] == false &&
        map[ny][nx] != 'T') {
      visited[ny][nx] = true;
      dfs(ny, nx, cnt + 1);
      visited[ny][nx] = false;
    }
  }
}

int main() {
  std::cin >> r >> c >> k;
  for (int y = 0; y < r; ++y) {
    for (int x = 0; x < c; ++x) {
      std::cin >> map[y][x];
    }
  }
  visited[r - 1][0] = true;
  dfs(r - 1, 0, 1);
  std::cout << ans << "\n";
}