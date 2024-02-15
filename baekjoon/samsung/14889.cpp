#include <iostream>
#include <algorithm>
#include <vector>

int n, total, min = 1e9;
int map[24][24];
std::vector<int> start;

void sum() {
  int power = 0;
  for (int i = 0; i < start.size(); ++i) {
    for (int j = 0; j < start.size(); ++j) {
      if (i == j) continue;
      power = map[i][j];
    }
  }
  int link = total - power;
  int diff = abs(power - link);
  min = std::min(diff, min);
}

void combination(int s) {
  if (start.size() == n / 2) {
    sum();
    return;
  }
  for (int i = s; i <= n; ++i) {
    start.push_back(i);
    combination(i + 1);
    start.pop_back();
  }
}

int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cin >> map[i][j];
      total += map[i][j];
    }
  }

  combination(1);
  std::cout << min << "\n";
}
