#include <iostream>
#include <algorithm>

int t, a, dp[51][51];
std::string str;
char map[51][51];
bool check[51][51];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool in(int y, int x) {
  return (1 <= y && y <= t && 1 <= x && x <= a);
}

int dfs(int y, int x) {
  if (!in(y, x) || map[y][x] == 'H') return 0;
  if (check[y][x]) {
    std::cout << "-1\n";
    exit(0);
  }

  int &ret = dp[y][x];
  if (ret) return ret;

  check[y][x] = true;
  int value = (int)map[y][x] - '0';
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i] * value;
    int nx = x + dx[i] * value;
    ret = std::max(ret, dfs(ny, nx) + 1);
  }
  check[y][x] = false;
  return ret;
}

int main() {
  std::cin >> t >> a;
  for (int i = 1; i <= t; ++i) {
    std::cin >> str;
    for (int j = 1; j <= a; ++j) {
      map[i][j] = str[j - 1];
    }
  }
  std::cout << dfs(1, 1) << "\n";
}