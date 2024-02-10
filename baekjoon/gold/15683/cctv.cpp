#include <iostream>
#include <vector>
#include <map>

int n, m, min = 987654321;
int cctv[6] = {0, 4, 2, 4, 4, 1};
int map[8][8];
int tmp[8][8];
struct cc {
  int y, x, kind;
};
std::vector<cc> pos;
std::vector<std::pair<cc, int>> com;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
std::vector<int> one[5] = {{}, {0}, {1}, {2}, {3}};
std::vector<int> two[3] = {{}, {1, 3}, {0, 2}};
std::vector<int> three[5] = {{}, {0, 1}, {1, 2}, {2, 3}, {3, 0}};
std::vector<int> four[5] = {{}, {3, 0, 1}, {0, 1, 2}, {1, 2, 3}, {2, 3, 0}};
std::vector<int> five = {0, 1, 2, 3};

void see(int sy, int sx, int dy, int dx) {
  if (dy == 0 && dx == 1) {
    for (int i = sx; i < m && map[sy][i] != 6; ++i) tmp[sy][i] = -1;
  } else if (dy == 0 && dx == -1) {
    for (int i = sx; i >= 0 && map[sy][i] != 6; --i) tmp[sy][i] = -1;
  } else if (dy == 1 && dx == 0) {
    for (int i = sy; i < n && map[i][sx] != 6; ++i) tmp[i][sx] = -1;
  } else {
    for (int i = sy; i >= 0 && map[i][sx] != 6; --i) tmp[i][sx] = -1;
  }
}

void view(int y, int x, int kind, int dir) {
  std::vector<int> cp;
  if (kind == 1) {
    cp = one[dir];
  } else if (kind == 2) {
    cp = two[dir];
  } else if (kind == 3) {
    cp = three[dir];
  } else if (kind == 4) {
    cp = four[dir];
  } else {
    cp = five;
  }
  for (auto i : cp) {
    see(y, x, dy[i], dx[i]);
  }
}

void check() {
  memcpy(tmp, map, sizeof(map));
  for (auto i : com) {
    view(i.first.y, i.first.x, i.first.kind, i.second);
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (tmp[i][j] == 0) {
        ++cnt;
      }
    }
  }
  min = std::min(min, cnt);
}

void combi(int depth) {
  if (depth == pos.size()) {
    check();
    return;
  }
  for (int i = 1; i <= cctv[pos[depth].kind]; ++i) {
    com.push_back({pos[depth], i});
    combi(depth + 1);
    com.pop_back();
  }
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
      if (map[i][j] > 0 && map[i][j] < 6) {
        pos.push_back({i, j, map[i][j]});
      }
    }
  }
  combi(0);
  std::cout << min << "\n";
}