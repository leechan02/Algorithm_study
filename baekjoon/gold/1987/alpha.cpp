#include <iostream>
#include <algorithm>

int r, c, ans;
char map[21][21];
bool visited[26];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int cnt) {
  ans = std::max(ans, cnt);
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
    int next = (int)(map[ny][nx] - 'A');
    if (visited[next] == false) {
      visited[next] = true;
      dfs(ny, nx, cnt + 1);
      visited[next] = false;
    }
  }
}

int main() {
  std::cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    std::cin >> map[i];
  }
  visited[(int)(map[0][0] - 'A')] = true;
  dfs(0, 0, 1);
  std::cout << ans << "\n";
}