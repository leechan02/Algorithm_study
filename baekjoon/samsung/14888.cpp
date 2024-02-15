#include <iostream>
#include <algorithm>
#include <vector>

int n, a[101], max = -1e9, min = 1e9;
std::vector<int> oper(4);
std::vector<int> list;

void cal() {
  int res = a[0];
  for (int i = 0; i < n - 1; ++i) {
    if (list[i] == 1) {
      res += a[i + 1];
    } else if (list[i] == 2) {
      res -= a[i + 1];
    } else if (list[i] == 3) {
      res *= a[i + 1];
    } else {
      res /= a[i + 1];
    }
  }
  max = std::max(res, max);
  min = std::min(res, min);
}

void permutation(int depth) {
  if (depth == list.size()) {
    cal();
    return;
  }
  for (int i = depth; i < list.size(); ++i) {
    std::swap(list[i], list[depth]);
    permutation(depth + 1);
    std::swap(list[i], list[depth]);
  }
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 0; i < 4; ++i) {
    std::cin >> oper[i];
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < oper[i]; ++j) {
      list.push_back(i + 1);
    }
  }
  permutation(0);
  std::cout << max << "\n";
  std::cout << min << "\n";
}