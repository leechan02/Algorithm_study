#include <cmath>
#include <iostream>
#include <vector>

#define INF 987654321

int n, m;
int ans = INF;
typedef std::pair<int, int> pos;
std::vector<pos> chicken;
std::vector<pos> house;
std::vector<int> com;

void route() {
  int res = 0;
  for (int i = 0; i < house.size(); ++i) {
    pos from = house[i];

    int min = INF;
    for (int j = 0; j < com.size(); ++j) {
      pos to = chicken[com[j]];
      min = std::min(min, abs(from.first - to.first) + abs(from.second - to.second));
    }
    res += min;
  }
  ans = std::min(ans, res);
}

void combi(int start) {
  if (com.size() == m) {
    route();
    return;
  }
  for (int i = start + 1; i < chicken.size(); ++i) {
    com.push_back(i);
    combi(i);
    com.pop_back();
  }
}

int main() {
  std::cin >> n >> m;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      int tmp;
      std::cin >> tmp;
      if (tmp == 1) {
        house.push_back({y, x});
      } else if (tmp == 2) {
        chicken.push_back({y, x});
      }
    }
  }

  combi(-1);
  std::cout << ans << "\n";
}