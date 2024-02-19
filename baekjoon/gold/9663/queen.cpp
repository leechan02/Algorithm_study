#include <iostream>
#include <vector>
#include <cmath>

int n, cnt, ny, nx;
std::vector<int> queen(16);

bool isSafe(int y, int x) {
  for (int by = 0; by < y; ++by) {
    int bx = queen[by];
    if (bx == x || std::abs(by - y) == std::abs(bx - x)) return false;
  }
  return true;
}

void dfs(int depth) {
  if (depth == n) {
    ++cnt;
    return;
  }

  for (int i = 0; i < n; ++i) {
      if (isSafe(depth, i)) {
        queen[depth] = i;
        dfs(depth + 1);
      }
  }
}

int main() {
  std::cin >> n;
  dfs(0);
  std::cout << cnt << "\n";
}