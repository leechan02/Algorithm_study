#include <iostream>
#include <vector>
#include <algorithm>

int n, m, k;
int map[54][54];
struct rotate{
  int r, c, s;
}excute[7];

int sum() {
  int ret = 987654321;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < m; ++j) {
      sum += map[i][j];
    }
    ret = std::min(ret, sum);
  }
  return ret;
}

void permutation(int depth) {
  if (depth == k) {

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
}