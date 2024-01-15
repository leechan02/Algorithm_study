#include <algorithm>
#include <cstring>
#include <iostream>

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int map[100][100];
bool visited[100][100];

void DFS(int y, int x) {
  visited[y][x] = true;

  for (int i = 0; i < 4; ++i) {
    int newX = x + dx[i];
    int newY = y + dy[i];

    if (newX >= 0 && newY >= 0 && visited[y][x] == false && map[y][x] != 0) {
      DFS(newY, newX);
    }
  }
}

int main() {
  int n;
  std::cin >> n;

  int max = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      int tmp;
      std::cin >> tmp;

      max = std::max(max, tmp);
      map[y][x] = tmp;
    }
  }

  int res = 0;
  for (int i = 0; i < max; ++i) {
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        if (map[y][x] <= i) {
          map[y][x] = 0;
        }
      }
    }

    int cnt = 0;
    memset(visited, 0, sizeof(visited));
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        if (map[y][x] != 0 && visited[y][x] == false) {
          ++cnt;
          DFS(y, x);
        }
      }
    }
    res = std::max(res, cnt);
  }
  std::cout << res << "\n";
}