#include <iostream>
#include <map>

int n, m, cnt, tmp;
std::map<int, int> map;

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;
    map[tmp]++;
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> tmp;
    map[tmp]++;
  }
  for (auto it : map) {
    if (it.second == 1) ++cnt;
  }
  std::cout << cnt << "\n";
}