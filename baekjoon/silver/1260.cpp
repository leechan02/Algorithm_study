#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> arr[1001];
bool DFSVisited[1001];
bool BFSVisited[1001];

void DFS(int index) {
  std::cout << index << " ";
  DFSVisited[index] = true;
  std::sort(arr[index].begin(), arr[index].end());
  for (int i = 0; i < arr[index].size(); ++i) {
    if (DFSVisited[arr[index][i]] == false) {
      DFS(arr[index][i]);
    }
  }
}

void BFS(int index) {
  std::queue<int> queue;

  queue.push(index);
  std::cout << index << " ";
  BFSVisited[index] = true;
  while (!queue.empty()) {
    int tmp = queue.front();
    queue.pop();
    std::sort(arr[index].begin(), arr[index].end());
    for (int i = 0; i < arr[tmp].size(); ++i) {
      if (BFSVisited[arr[tmp][i]] == false) {
        BFSVisited[arr[tmp][i]] = true;
        queue.push(arr[tmp][i]);
        std::cout << arr[tmp][i] << " ";
      }
    }
  }
}

int main() {
  int N, M, V, a, b;
  std::cin >> N >> M >> V;

  for (int i = 0; i < M; ++i) {
    std::cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }

  DFS(V);
  std::cout << '\n';
  BFS(V);
  return (0);
}