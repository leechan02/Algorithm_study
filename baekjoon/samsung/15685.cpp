#include <iostream>
#include <vector>

int n, cnt, x, y, nx, ny, d, g;
int map[101][101];
int dy[4] = {0, -1, 0, 1}; // right, up, left, down
int dx[4] = {1, 0, -1, 0};

void dragonCurve() {
  std::vector<int> curve;

  map[y][x] = 1;
  ny = y + dy[d];
  nx = x + dx[d];
  map[ny][nx] = 1;
  curve.push_back((d + 2) % 4);
  for (int i = 0; i < g; ++i){
    for (int j = curve.size() - 1; j >= 0; --j) {
      d = (curve[j] + 3) % 4;
      ny = ny + dy[d];
      nx = nx + dx[d];
      map[ny][nx] = 1;
      curve.push_back((d + 2) % 4);
    }
  }
}

int isSquare(int y, int x) {
  if (map[y][x] == 0) return 0;
  if (x + 1 > 100 || map[y][x + 1] == 0) return 0;
  if (y + 1 > 100 || map[y + 1][x] == 0) return 0;
  if (map[y + 1][x + 1] == 0) return 0;
  return 1;
}

void findSquare() {
  for (int i = 0; i < 101; ++i) {
    for (int j = 0; j < 101; ++j) {
      if (isSquare(i, j)) ++cnt;
    }
  }
}

int main() {
  std::cin >> n;
  while (n--) {
    std::cin >> x >> y >> d >> g;
    dragonCurve();
  }
  findSquare();
  std::cout << cnt << "\n";
}