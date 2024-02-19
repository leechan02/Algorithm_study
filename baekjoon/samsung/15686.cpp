#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int n, m, min = 1e9, sum;
int map[51][51];
typedef std::pair<int, int> pos;
std::vector<pos> chicken;
std::vector<pos> house;
std::vector<pos> com;

void len() {
  sum = 0;
  for (auto pos : house) {
    int to = 1e9;
    for (auto i : com) {
      int tmp = abs(pos.first - i.first) + abs(pos.second - i.second);
      to = std::min(to, tmp);
    }
    sum += to;
  }
  min = std::min(sum, min);
}

void combination(int start) {
  if (com.size() == m) {
    len();
    return;
  }

  for (int i = start; i < chicken.size(); ++i) {
    com.push_back(chicken[i]);
    combination(i + 1);
    com.pop_back();
  }
}

int main() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cin >> map[i][j];
      if (map[i][j] == 2) chicken.push_back({i, j});
      else if (map[i][j] == 1) house.push_back({i, j});
    }
  }
  combination(0);
  std::cout << min << "\n";
}