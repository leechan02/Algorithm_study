#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int n, total, min = 1e9;
int map[24][24];
bool visited[21];
std::vector<int> start;
std::vector<int> link;

void team() {
  for (int i = 1; i <= n ; ++i) {
    if (visited[i] == false) link.push_back(i);
  }
  int spower = 0, lpower = 0;
  for (int i = 0; i < n / 2; ++i) {
    for (int j = 0; j < n / 2; ++j) {
      spower += map[start[i]][start[j]];
      lpower += map[link[i]][link[j]];
    }
  }
  int diff = abs(spower - lpower);
  min = std::min(diff, min);
  link.clear();
}

void combination(int s) {
  if (start.size() == n / 2) {
    team();
    return;
  }
  for (int i = s; i <= n; ++i) {
    visited[i] = true;
    start.push_back(i);
    combination(i + 1);
    start.pop_back();
    visited[i] = false;
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
