#include <iostream>
#include <string>

int n, a, b, ny, nx;
char map[101][101];
bool normal[101][101], abnormal[101][101];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs1(int y, int x) {
  normal[y][x] = true;
  for (int i = 0; i < 4; ++i) {
    ny = y + dy[i];
    nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n)
      continue;
    if (normal[ny][nx] == true || map[ny][nx] != map[y][x])
      continue;
    dfs1(ny, nx);
  }
}

void dfs2(int y, int x) {
  abnormal[y][x] = true;
  for (int i = 0; i < 4; ++i) {
    ny = y + dy[i];
    nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n || abnormal[ny][nx] == true)
      continue;
    if (map[y][x] == map[ny][nx] || (map[ny][nx] == 'R' && map[y][x] == 'G') ||
        (map[ny][nx] == 'G' && map[y][x] == 'R')) {
      dfs2(ny, nx);
    }
  }
}

int main() {
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (normal[i][j] == false) {
        dfs1(i, j);
        ++a;
      }
      if (abnormal[i][j] == false) {
        dfs2(i, j);
        ++b;
      }
    }
  }

  std::cout << a << " " << b << "\n";
}