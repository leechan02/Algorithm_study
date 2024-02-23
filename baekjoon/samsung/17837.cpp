#include <iostream>
#include <vector>

int n, k, y, x, d, cnt;
int map[15][15];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
struct chess{
  int idx, d;
};
struct pos{
  int y, x;
};
std::vector<chess> stack[15][15];
std::vector<pos> list;

bool check() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (stack[i][j].size() > 3) return false;
    }
  }
  return true;
}

bool move() {
  for (int i = 0; i < k; ++i) {
    y = list[i].y, x = list[i].x;
    if (stack[y][x].size() > 3) {
      ++cnt;
      return false;
    }
    int j = 0;
    for (; j < stack[y][x].size(); ++j) if (stack[y][x][j].idx == i) break;
    int ny = y + dy[stack[y][x][j].d], nx = x + dx[stack[y][x][j].d];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == 2) {
      if (stack[y][x][j].d == 0 || stack[y][x][j].d == 2) stack[y][x][j].d += 1;
      else if (stack[y][x][j].d == 1 || stack[y][x][j].d == 3) stack[y][x][j].d -= 1;
      ny = y + dy[stack[y][x][j].d], nx = x + dx[stack[y][x][j].d];
      if (ny >= 0 && ny < n && nx >= 0 && nx < n && map[ny][nx] != 2) --i;
    } else if (map[ny][nx] == 1) {
      for (int t = stack[y][x].size() - 1; t >= j; --t) {
        int idx = stack[y][x][t].idx, d = stack[y][x][t].d;
        stack[ny][nx].push_back({idx, d});
        list[idx].y = ny, list[idx].x = nx;
      }
      int pop = stack[y][x].size() - j;
      while (pop--) stack[y][x].pop_back();
    } else {
      for (int t = j; t < stack[y][x].size(); ++t) {
        int idx = stack[y][x][t].idx, d = stack[y][x][t].d;
        stack[ny][nx].push_back({idx, d});
        list[idx].y = ny, list[idx].x = nx;
      }
      int pop = stack[y][x].size() - j;
      while (pop--) stack[y][x].pop_back();
    }
  }
  ++cnt;
  if (check() == false) return false;
  return true;
}

int main() {
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
    }
  }
  for (int i = 0; i < k; ++i) {
    std::cin >> y >> x >> d;
    stack[y - 1][x - 1].push_back({i, d - 1});
    list.push_back({y - 1, x - 1});
  }
  while(move()) {
    if (cnt > 1000) {
      std::cout << "-1\n";
      return 0;
    }
  }
  std::cout << cnt << "\n";
}