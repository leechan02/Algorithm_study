#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int n;
long long num[11];
std::vector<int> oper;
long long min = 9876543210, max = -9876543210;

void cal() {
  long long res = num[0];
  for (int i = 0; i < n - 1; ++i) {
    long long a = res, b = num[i + 1];
    if (oper[i] == 0) {
      res = a + b;
    } else if (oper[i] == 1) {
      res = a - b;
    } else if (oper[i] == 2) {
      res = a * b;
    } else {
      res = a / b;
    }
  }
  min = std::min(min, res);
  max = std::max(max, res);
}

void permutation(int depth) {
  if (depth == n - 1) {
    cal();
    return;
  }
  for (int i = depth; i < n - 1; ++i) {
    std::swap(oper[i], oper[depth]);
    permutation(depth + 1);
    std::swap(oper[i], oper[depth]);
  }
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> num[i];
  }
  for (int i = 0; i < 4; ++i) {
    int cnt;
    std::cin >> cnt;
    while (cnt--) {
      oper.push_back(i);
    }
  }
  permutation(0);
  std::cout << max << "\n";
  std::cout << min << "\n";
}