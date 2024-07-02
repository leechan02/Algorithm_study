#include <iostream>
#include <string>
#include <algorithm>

std::string tmp;
int n, h, ny, nx;
int map[26][26];
int house[1000];
bool visited[26][26];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int home) {
  ++house[home];
  visited[y][x] = true;

  for (int i = 0; i < 4; ++i) {
    ny = y + dy[i];
    nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
    if (map[ny][nx] == 1) {
      dfs(ny, nx, home);
    }
  }
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;
    for (int j = 0; j < n; ++j) {
      map[i][j] = tmp[j] - '0';
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map[i][j] == 1 && !visited[i][j]) {
        dfs(i, j, h);
        ++h;
      }
    }
  }

  std::sort(house, house + h);

  std::cout << h << "\n";
  for (int i = 0; i < h; ++i) {
    std::cout << house[i] << "\n";
  }
}