#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

std::vector<int> dwarf(9, 0);

void print(std::vector<int> real) {
  for (auto i : real) {
    std::cout << i << "\n";
  }
}

void combi(int start, std::vector<int> real) {
  if (real.size() == 7) {
    if (std::accumulate(real.begin(), real.end(), 0) == 100) {
      print(real);
      exit(0);
    }
    return;
  }
  for (int i = start + 1; i < 9; ++i) {
    real.push_back(dwarf[i]);
    combi(i, real);
    real.pop_back();
  }
}

int main() {
  for (int i = 0; i < 9; ++i) {
    std::cin >> dwarf[i];
  }
  std::sort(dwarf.begin(), dwarf.end());

  std::vector<int> real;
  combi(-1, real);
}