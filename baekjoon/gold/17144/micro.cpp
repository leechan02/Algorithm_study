#include <iostream>

int n, m, t;
int map[51][51];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
typedef std::pair<int, int> pos;
std::vector<pos> air;

void spread() {
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      if (map[y][x] != 0 && map[y][x] != -1) {
        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
          int ny = y + dy[i];
          int nx = x + dx[i];
          if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] != -1) {
            ++cnt;
            map[ny][nx] += map[y][x] / 5;
          }
        }
        map[y][x] -= (map[y][x] / 5) * cnt;
      }
    }
  }
}

void print() {
  std::cout << "\n";
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      std::cout << map[y][x] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  std::cin >> n >> m >> t;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      int tmp;
      std::cin >> tmp;
      if (tmp == -1) {
        air.push_back({y, x});
      }
      map[y][x] = tmp;
    }
  }
  print();

  while (t--) {
    spread();
    // conditioner();
  }
  print();

  int left_dust = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      if (map[y][x] != 0 && map[y][x] != -1) {
        left_dust += map[y][x];
      }
    }
  }
  std::cout << left_dust << "\n";
}