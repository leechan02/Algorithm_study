#include <iostream>
#include <vector>

std::vector<int> arr[2001];
bool visited[2001];

bool DFS(int index, int depth) {
  if (depth == 4) {
    return true;
  }
  visited[index] = true;
  for (int i = 0; i < arr[index].size(); ++i) {
    if (visited[arr[index][i]] == false) {
      if (DFS(arr[index][i], depth + 1)) {
        return true;
      }
    }
  }
  visited[index] = false;
  return false;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, M, a, b;
  std::cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    std::cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }

  for (int i = 0; i < N; ++i) {
    if (DFS(i, 0)) {
      std::cout << "1" << '\n';
      return (0);
    }
  }
  std::cout << "0" << '\n';
  return (0);
}