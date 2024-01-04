#include <iostream>
#include <vector>

std::vector<int> tree[100001];
std::vector<bool> visited;
int answer = 0;
int deleteNode = 0;

void DFS(int num) {
  visited[num] = true;
  int childNode = 0;

  for (int i : tree[num]) {
    if (visited[i] == false && i != deleteNode) {
      ++childNode;
      DFS(i);
    }
  }
  if (childNode == 0) {
    ++answer;
  }
}

int main() {
  int n;
  std::cin >> n;

  visited.resize(n + 1, false);
  
  int root = 0;
  for (int i = 0; i < n; ++i) {
    int parent;
    std::cin >> parent;

    if (parent == -1) {
      root = i;
    } else {
      tree[i].push_back(parent);
      tree[parent].push_back(i);
    }
  }

  std::cin >> deleteNode;
  if (deleteNode == root) {
    std::cout << "0\n";
  } else {
    DFS(root);
    std::cout << answer << "\n";
  }
  return (0);
}