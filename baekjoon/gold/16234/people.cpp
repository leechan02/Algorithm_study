#include <iostream>
#include <vector>

int n, l, r;
int sum, ans;
int map[51][51];
bool visited[51][51];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
std::vector<std::pair<int, int>> v;

void dfs(int y, int x) {
  for (int i = 0; i < 4; ++i) {
    int newY = y + dy[i];
    int newX = x + dx[i];
    if (newY < 0 || newX < 0 || newY >= n || newX >= n ||
        visited[newY][newX] == true) {
      continue;
    }
    int com = std::abs(map[newY][newX] - map[y][x]);
    if (com >= l && com <= r) {
      visited[newY][newX] = true;
      v.push_back({newY, newX});
      sum += map[newY][newX];
      dfs(newY, newX);
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

  while (true) {
    bool flag = 0;
    memset(visited, 0, sizeof(visited));
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        if (visited[y][x] == false) {
          v.clear();
          visited[y][x] = true;
          v.push_back({y, x});
          sum = map[y][x];
          dfs(y, x);
          if (v.size() == 1) {
            continue;
          }
          for (auto b : v) {
            map[b.first][b.second] = sum / v.size();
            flag = 1;
          }
        }
      }
    }
    if (!flag) {
      break;
    }
    ++ans;
  }
  std::cout << ans << "\n";
}