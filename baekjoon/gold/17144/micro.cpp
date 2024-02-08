#include <iostream>
#include <vector>
#include <cstring>

int n, m, t;
int map[51][51];
int tmp[51][51];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
std::vector<int> air;

void spread() {
  memset(tmp, 0, sizeof(tmp));
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      if (map[y][x] != 0 && map[y][x] != -1) {
        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
          int ny = y + dy[i];
          int nx = x + dx[i];
          if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] != -1) {
            ++cnt;
            tmp[ny][nx] += map[y][x] / 5;
          }
        }
        map[y][x] -= (map[y][x] / 5) * cnt;
      }
    }
  }
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      if (tmp[y][x] != 0) {
        map[y][x] += tmp[y][x];
      }
    }
  }
}

void conditioner() {
    int sy = air[0];
    for (int i = sy - 1; i > 0; --i) {
      map[i][0] = map[i - 1][0];
    }
    for (int i = 0; i < m; ++i) {
      map[0][i] = map[0][i + 1];
    }
    for (int i = 0; i < sy; ++i) {
      map[i][m - 1] = map[i + 1][m - 1];
    }
    for (int i = m; i > 1; --i) {
      map[sy][i] = map[sy][i - 1];
    }
    map[sy][1] = 0;
    sy = air[1];
    for (int i = sy + 1; i < n; ++i) {
      map[i][0] = map[i + 1][0];
    }
    for (int i = 0; i < m; ++i) {
      map[n - 1][i] = map[n - 1][i + 1];
    }
    for (int i = n; i > sy; --i) {
      map[i][m - 1] = map[i - 1][m - 1];
    }
    for (int i = m; i > 1; --i) {
      map[sy][i] = map[sy][i - 1];
    }
    map[sy][1] = 0;
}

int main() {
  std::cin >> n >> m >> t;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      int tmp;
      std::cin >> tmp;
      if (tmp == -1) {
        air.push_back(y);
      }
      map[y][x] = tmp;
    }
  }
  while (t--) {
    spread();
    conditioner();
  }

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