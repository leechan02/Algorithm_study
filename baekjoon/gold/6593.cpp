#include <iostream>
#include <queue>
#include <string>

struct pos{
  int z, y, x;
};

int l, r, c, nz, ny, nx;
int map[31][31][31];
std::string tmp;
int dz[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dx[6] = {1, -1, 0, 0, 0, 0};
std::queue<pos> q;
pos e;

void bfs() {
  while (!q.empty()) {
    pos cur = q.front(); q.pop();

    for (int i = 0; i < 6; ++i) {
      nz = cur.z + dz[i];
      ny = cur.y + dy[i];
      nx = cur.x + dx[i];
      if (nz < 0 || nz >= l || ny < 0 || ny >= r || nx < 0 || nx >= c || map[nz][ny][nx] != 0) continue;
      map[nz][ny][nx] = map[cur.z][cur.y][cur.x] + 1;
      q.push({nz, ny, nx});
    }
  }
}

int main() {
  while (true) {
    std::cin >> l >> r >> c;
    if (l == 0 && r == 0 && c == 0) return 0;

    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < r; ++j) {
        std::cin >> tmp;
        for (int k = 0; k < c; ++k) {
          if (tmp[k] == 'S') {
            q.push({i, j, k});
          } else if (tmp[k] == 'E') {
            e = {i, j, k};
          }
          if (tmp[k] == '#') {
            map[i][j][k] = -1;
          } else {
            map[i][j][k] = 0;
          }
        }
      }
    }

    bfs();

    int x = map[e.z][e.y][e.x];
    if (x) std::cout << "Escaped in " << x << " minute(s).\n";
    else std::cout << "Trapped!\n";
  }
}