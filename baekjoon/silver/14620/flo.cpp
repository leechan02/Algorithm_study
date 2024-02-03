#include <iostream>
#include <algorithm>

#define INF 987654321

int n, ans = INF;
int map[11][11];
int visited[11][11];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool check(int y, int x) {
  if (visited[y][x]) return false;
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) {
      return false;
    }
  }
  return true;
}

int setFlower(int y, int x) {
  visited[y][x] = true;
  int sum = map[y][x];
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    visited[ny][nx] = true;
    sum += map[ny][nx];
  }
  return sum;
}

void eraseFlower(int y, int x) {
  visited[y][x] = false;
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    visited[ny][nx] = false;
  }
}

void flower(int cnt, int sum) {
  if (cnt == 3) {
    ans = std::min(ans, sum);
    return;
  }
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      if (check(y, x)) {
        flower(cnt + 1, sum + setFlower(y, x));
        eraseFlower(y, x);
      }
    }
  }
}

int main() {
  std::cin >> n;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      std::cin >> map[y][x];
    }
  }
  flower(0, 0);
  std::cout << ans;
}