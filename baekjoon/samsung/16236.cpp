#include <iostream>
#include <queue>

int n, sy, sx, size = 2, cnt;
int map[21][21];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool visited[21][21];

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
      if (map[i][j] == 9) sy = i, sx = j;
    }
  }
}