#include <iostream>
#include <vector>
#include <map>

int n, m;

int main() {
  std::ios::sync_with_stdio(0); std::cout.tie(0); std::cin.tie(0);
  std::cin >> n >> m;

  std::vector<std::string> pokemon(n + 1);
  std::map<std::string, int> poke;
  for (int i = 1; i <= n; ++i) {
    std::string tmp;
    std::cin >> tmp;

    pokemon[i] = tmp;
    poke[tmp] = i;
  }

  for (int i = 0; i < m; ++i) {
    std::string tmp;
    std::cin >> tmp;

    if (tmp[0] >= '0' && tmp[0] <= '9') {
      std::cout << pokemon[std::atoi(tmp.c_str())] << "\n";
    } else {
      std::cout << poke[tmp] << "\n";
    }
  }
  return (0);
}