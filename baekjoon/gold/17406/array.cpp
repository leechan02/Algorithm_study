#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int n, m, k;
int ans = 987654321;
int map[54][54];
int tmp[54][54];
struct rotate {
  int r, c, s;
}excute[7];
struct temp {
  int y, x, w;
};


int sum() {
  int ret = 987654321;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < m; ++j) {
      sum += tmp[i][j];
    }
    ret = std::min(ret, sum);
  }
  return ret;
}

void move(int sy, int sx, int ey, int ex) {
  std::vector<temp> pos;
  for (int i = sx + 1; i <= ex; ++i) {
    pos.push_back({sy, i, tmp[sy][i - 1]});
  }
  for (int i = sy + 1; i <= ey; ++i) {
    pos.push_back({i, ex, tmp[i - 1][ex]});
  }
  for (int i = ex - 1; i >= sx; --i) {
    pos.push_back({ey, i, tmp[ey][i + 1]});
  }
  for (int i = ey - 1; i >= sy; --i) {
    pos.push_back({i, sx, tmp[i + 1][sx]});
  }
  for (auto i : pos) {
    tmp[i.y][i.x] = i.w;
  }
}

int rot() {
  for (int i = 0; i < k; ++i) {
    int sy = excute[i].c - excute[i].s - 1;
    int sx = excute[i].r - excute[i].s - 1;
    int ey = excute[i].c + excute[i].s - 1;
    int ex = excute[i].r + excute[i].s - 1;
    int depth = (ey - sy + 1) / 2;
    while (depth--) {
      move(sy, sx, ey, ex);
      ++sy, ++sx, --ey, --ex;
    }
  }
  return sum();
}

void permutation(int depth) {
  if (depth == k) {
    memcpy(tmp, map, sizeof(map));
    ans = std::min(ans, rot());
  }
  for (int i = depth; i < k; ++i) {
    std::swap(excute[i], excute[depth]);
    permutation(depth + 1);
    std::swap(excute[i], excute[depth]);
  }
}

int main() {
  std::cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
    }
  }
  for (int i = 0; i < k; ++i) {
    std::cin >> excute[i].c >> excute[i].r >> excute[i].s;
  }
  permutation(0);
  std::cout << ans << "\n";
}