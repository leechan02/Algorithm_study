#include <iostream>

int n, l, r;
int sum, cnt;
int map[51][51];
bool visited[51][51];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x) {
  ++cnt;
  sum += map[y][x];
  visited[y][x] = true;
  for (int i = 0; i < 4; ++i) {
    int newY = y + dy[i];
    int newX = x + dx[i];
    if (newY < 0 || newX < 0 || newY >= n || newX >= n ||
        visited[newY][newX] == true) {
      continue;
    }
    int com = std::abs(map[newY][newX] - map[y][x]);
    if (com >= l && com <= r) {
      dfs(newY, newX);
    }
  }
}

void init(int init) {
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      if (map[y][x] == true) {
        map[y][x] = init;
      }
    }
  }
}

int main() {
  std::cin >> n >> l >> r;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      std::cin >> map[y][x];
    }
  }

  int ans = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      if (visited[y][x] == false) {
        sum = 0, cnt = 0;
        dfs(y, x);
        if (sum != 0) {
          ++ans;
          init(sum / cnt);
        }
      }
    }
  }
  std::cout << ans << "\n";
}