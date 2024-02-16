#include <iostream>
#include <vector>

int n, m, y, x, ny, nx, k;
int map[21][21];
int order[1001];
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};
std::vector<int> dice(6);

void move(int d) {
  ny = y + dy[d];
  nx = x + dx[d];
  if (ny < 0 || ny >= n || nx < 0 || nx >= m) return;
  y = ny, x = nx;

  if (d == 1) {
    dice = {dice[3], dice[2], dice[0], dice[1], dice[4], dice[5]};
  } else if (d == 2) {
    dice = {dice[2], dice[3], dice[1], dice[0], dice[4], dice[5]};
  } else if (d == 3) {
    dice = {dice[4], dice[5], dice[2], dice[3], dice[1], dice[0]};
  } else {
    dice = {dice[5], dice[4], dice[2], dice[3], dice[0], dice[1]};
  }

  std::cout << dice[0] << "\n";

  if (map[y][x] == 0) {
    map[y][x] = dice[1];
  } else {
    dice[1] = map[y][x];
    map[y][x] = 0;
  }
}

int main() {
  std::cin >> n >> m >> y >> x >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
    }
  }
  for (int i = 0; i < k ; ++i) {
    std::cin >> order[i];
  }
  for (int i = 0; i < k; ++i) {
    move(order[i]);
  }
}