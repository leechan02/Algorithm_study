#include <iostream>
#include <map>
#include <vector>

int n, m;
std::map<std::string, int> map;

int main() {
  std::cin >> n >> m;

  for (int i = 0; i < n + m; ++i) {
    std::string tmp;
    std::cin >> tmp;

    ++map[tmp];
  }

  int cnt = 0;
  std::vector<std::string> res;
  for (auto i : map) {
    if (i.second == 2) {
      ++cnt;
      res.push_back(i.first);
    }
  }

  std::cout << cnt << "\n";
  for (auto i : res) {
    std::cout << i << "\n";
  }
}