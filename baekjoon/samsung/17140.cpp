#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int r, c, k, yc, xc;
int map[101][101];
int num[101];
std::vector<int> tmp;
struct pos {
  int n, c;

  bool operator<(const pos& other) const {
    if (c != other.c) return c < other.c;
    return n < other.n;
  }
};

bool checkCommand() {
  int my = 0, mx = 0;
  for (int i = 0; i < 100; ++i) {
    int tmp = 0;
    for (int j = 0; j < 100; ++j) {
      if (map[i][j] == 0) break;
      ++tmp;
    }
    mx = std::max(mx, tmp);
  }
  for (int j = 0; j < 100; ++j) {
    int tmp = 0;
    for (int i = 0; i < 100; ++i) {
      if (map[i][j] == 0) break;
      ++tmp;
    }
    my = std::max(my, tmp);
  }
  if (my >= mx) return true;
  return false;
}

void makeSortY(int idx) {
  if (tmp.size() == 0) return;
  memset(num, 0, sizeof(num));
  std::vector<pos> next;
  for (auto i : tmp) {
    num[i]++;
  }

  for (int i = 1; i <= 100; ++i) {
    if (num[i] == 0) continue;
    next.push_back({i, num[i]});
  }
  std::sort(next.begin(), next.end());

  int x = 0;
  for (auto t : next) {
    if (x > 98) break;
    map[idx][x] = t.n;
    map[idx][x + 1] = t.c;
    x += 2;
  }
  while (x < 99) map[idx][x++] = 0;
}

void makeSortX(int idx) {
  if (tmp.size() == 0) return;
  memset(num, 0, sizeof(num));
  std::vector<pos> next;
  for (auto i : tmp) {
    num[i]++;
  }

  for (int i = 1; i <= 100; ++i) {
    if (num[i] == 0) continue;
    next.push_back({i, num[i]});
  }
  std::sort(next.begin(), next.end());

  int y = 0;
  for (auto t : next) {
    if (y > 98) break;
    map[y][idx] = t.n;
    map[y + 1][idx] = t.c;
    y += 2;
  }
  while (y < 99) map[y++][idx] = 0;
}

void sortX() {
  for (int j = 0; j < 100; ++j) {
    for (int i = 0; i < 100; ++i) {
      if (map[i][j] == 0) continue;;
      tmp.push_back(map[i][j]);
    }
    makeSortX(j);
    tmp.clear();
  }
}

void sortY() {
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      if (map[i][j] == 0) continue;;
      tmp.push_back(map[i][j]);
    }
    makeSortY(i);
    tmp.clear();
  }
}

int main() {
  std::cin >> r >> c >> k;
  --r, --c;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3;  ++j) {
      std::cin >> map[i][j];
    }
  }
  for (int t = 0; t <= 100; ++t) {
    if (map[r][c] == k) {
      std::cout << t << "\n";
      return 0;
    }
    if (checkCommand()) {
      sortY();
    } else {
      sortX();
    }
  }
  std::cout << -1 << "\n";
  return 0;
}