#include <iostream>
#include <vector>

std::vector<int> arr[1001];
bool visited[1001];

void DFS(int index) {
  visited[index] = true;
  for (int i = 0; i < arr[index].size(); ++i) {
    int j = arr[index][i];
    if (visited[j] == false) {
      DFS(j);
    }
  }
}

int main() {
  int N, M, u, v;
  std::cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    std::cin >> u >> v;
    arr[u].push_back(v);
    arr[v].push_back(u);
  }

  int cnt = 0;
  for (int i = 1; i <= N; ++i) {
    if (visited[i] == false) {
      cnt++;
      DFS(i);
    }
  }
  std::cout << cnt << '\n';
}