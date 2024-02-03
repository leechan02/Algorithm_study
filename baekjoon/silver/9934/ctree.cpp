#include <iostream>
#include <vector>

int depth;
int enter[1030];
std::vector<int> tree[11];

void dfs(int start, int end, int level) {
  if (start > end) return;
  if (start == end) {
    tree[level].push_back(enter[start]);
    return;
  }
  int mid = (start + end) / 2;
  tree[level].push_back(enter[mid]);
  dfs(start, mid - 1, level + 1);
  dfs(mid + 1, end, level + 1);
}

int main() {
  std::cin >> depth;
  int end = std::pow(2, depth) - 1;
  for (int i = 0; i < end; ++i) {
    std::cin >> enter[i];
  }
  dfs(0, end, 1);
  for (int i = 1; i <= depth; ++i) {
    for (auto j : tree[i]) {
      std::cout << j << " ";
    }
    std::cout << "\n";
  }
}