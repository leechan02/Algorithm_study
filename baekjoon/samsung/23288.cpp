#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

int n, m, k, d, sy, sx, ny, nx, score;
int map[21][21];
bool visited[21][21];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
std::vector<int> dice = {1, 6, 3, 4, 5, 2}; // up down east west south north

void moveDice() {
  // east, south, west, north
  if (d == 0) {
    dice = {dice[3], dice[2], dice[0], dice[1], dice[4], dice[5]};
  } else if (d == 1) {
    dice = {dice[5], dice[4], dice[2], dice[3], dice[0], dice[1]};
  } else if (d == 2) {
    dice = {dice[2], dice[3], dice[1], dice[0], dice[4], dice[5]};
  } else {
    dice = {dice[4], dice[5], dice[2], dice[3], dice[1], dice[0]};
  }
}

int getScore(int b) {
  memset(visited, 0, sizeof(visited));
  std::queue<std::pair<int, int>> q;
  q.push({sy, sx});
  visited[sy][sx] = true;

  int cnt = 1;
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int my = y + dy[i];
      int mx = x + dx[i];
      if (my < 0 || my >= n || mx < 0 || mx >= m || visited[my][mx] == true || map[my][mx] != b) continue;
      q.push({my, mx});
      visited[my][mx] = true;
      ++cnt;
    }
  }
  return cnt;
}

void move() {
  ny = sy + dy[d];
  nx = sx + dx[d];
  if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
    ++k;
    if (d == 0 || d == 1) d += 2;
    else d -= 2;
    return;
  }
  sy = ny, sx = nx;
  moveDice();
  int a = dice[1];
  int b = map[sy][sx];
  int c = getScore(b);
  score += (b * c);
  if (a > b) {
    d = (d + 1) % 4;
  } else if (a < b) {
    d = (d + 3) % 4;
  }
}

int main() {
  std::cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
    }
  }

  while (k--) {
    move();
  }

  std::cout << score << "\n";
}