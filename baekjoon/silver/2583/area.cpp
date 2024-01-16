#include <iostream>
#include <vector>
#include <algorithm>

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int map[101][101];
bool visited[101][101];
std::vector<int> res;
int area;

void DFS(int y, int x) {
  ++area;
  visited[y][x] = true;

  for (int i = 0; i < 4; ++i) {
    int newY = y + dy[i];
    int newX = x + dx[i];

    if (newY >= 0 && newX >= 0 && visited[newY][newX] == false &&
        map[newY][newX] == 1) {
      DFS(newY, newX);
    }
  }
}

int main() {
  int m, n, k;
  std::cin >> m >> n >> k;

  for (int y = 0; y < m; ++y) {
    for (int x = 0; x < n; ++x) {
      map[y][x] = 1;
    }
  }

  for (int i = 0; i < k; ++i) {
    int lx, ly, rx, ry;
    std::cin >> lx >> ly >> rx >> ry;

    for (int y = ly; y < ry; ++y) {
      for (int x = lx; x < rx; ++x) {
        map[y][x] = 0;
      }
    }
  }

  int cnt = 0;
  for (int y = 0; y < m; ++y) {
    for (int x = 0; x < n; ++x) {
      if (visited[y][x] == false && map[y][x] == 1) {
        ++cnt;
        area = 0;
        DFS(y, x);
        res.push_back(area);
      }
    }
  }

  std::sort(res.begin(), res.end());
  std::cout << cnt << "\n";
  for (int i : res) {
    std::cout << i << " ";
  }
}