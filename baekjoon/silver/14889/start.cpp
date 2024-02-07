#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int n, team, ans = 987654321;
int map[21][21];
bool visited[21];
std::vector<int> tmp;

int check(std::vector<int> &a, std::vector<int> &b) {
  int start = 0, link = 0;
  for (int i = 0; i < n / 2; ++i) {
    for (int j = 0; j < n / 2; ++j) {
      if (i == j) continue;
      start += map[a[i]][a[j]];
      link += map[b[i]][b[j]];
    }
  }
  return std::abs(start - link);
}

void combi(int start) {
  if (tmp.size() == team) {
    std::vector<int> start, link;
    for (int i = 0; i < n; ++i) {
      if (visited[i]) {
        start.push_back(i);
      } else {
        link.push_back(i);
      }
    }
    ans = std::min(ans, check(start, link));
    return;
  }
  for (int i = start + 1; i < n; ++i) {
    visited[i] = true;
    tmp.push_back(i);
    combi(i);
    tmp.pop_back();
    visited[i] = false;
  }
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
    }
  }
  team = n / 2;
  combi(-1);
  std::cout << ans << "\n";
}