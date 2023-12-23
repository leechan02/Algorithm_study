#include <iostream>
#include <vector>
#include <stack>

std::vector<std::vector<int>> A;
std::vector<int> check;
std::vector<bool> visited;
bool IsEven;

void DFS(int node) {
  visited[node] = true;

  for (int i : A[node]) {
    if (!visited[i]) {
      check[i] = (check[node] + 1) % 2;
      DFS(i);
    } else if (check[node] == check[i]) {
      IsEven = false;
    }
  }
}

int main() {
  int k;
  std::cin >> k;

  while (k--) {
    int v, e;
    std::cin >> v >> e;
    A.resize(v + 1);
    visited.resize(v + 1);
    check.resize(v + 1);
    IsEven = true;

    for (int i = 0; i <e; ++i) {
      int s, e;
      std::cin >> s >> e;
      A[s].push_back(e);
      A[e].push_back(s);
    }

    for (int i = 1; i <= v; ++i) {
      if (IsEven) {
        DFS(i);
      } else {
        break;
      }
    }
    if (IsEven) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
    for (int i = 0; i <= v; ++i) {
      A[i].clear();
      visited[i] = false;
      check[i] = 0;
    }
  }
  return (0);
}