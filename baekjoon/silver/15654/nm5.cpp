#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
bool visited[10000];
std::vector<int> num, tmp;

void permutation() {
  if (tmp.size() == m) {
    for (int i = 0; i < m; ++i) {
      std::cout << tmp[i] << " ";
    }
    std::cout << "\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (visited[num[i]]) continue;
    visited[num[i]] = true;
    tmp.push_back(num[i]);
    permutation();
    tmp.pop_back();
    visited[num[i]] = false;
  }
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int t;
    std::cin >> t;
    num.push_back(t);
  }
  std::sort(num.begin(), num.end());

  permutation();
}