#include <iostream>
#include <vector>

int n, m;
std::vector<int> num;
std::vector<int> tmp;

void combination(int start) {
  if (tmp.size() == m) {
    for (auto t : tmp) {
      std::cout << t << " ";
    }
    std::cout << "\n";
    return;
  }
  for (int i = start; i < n; ++i) {
    tmp.push_back(num[i]);
    combination(i);
    tmp.pop_back();
  }
}

int main() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    num.push_back(i);
  }
  combination(0);
}