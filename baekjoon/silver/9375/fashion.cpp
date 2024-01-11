#include <iostream>
#include <map>

int test, n;
std::string name, type;

int main() {
  std::cin >> test;

  for (int i = 0; i < test; ++i) {
    std::cin >> n;

    std::map<std::string, int> clothes;
    for (int ii = 0; ii < n; ++ii) {
      std::cin >> name >> type;
      ++clothes[type];
    }
    int sum = 1;
    for (auto ii : clothes) {
      sum *= (ii.second + 1);
    }
    std::cout << sum  - 1 << "\n";
  }
  return (0);
}