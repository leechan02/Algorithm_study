#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> A;
std::vector<int> answer;
std::vector<bool> visited;

void BFS(int start) {
  std::queue<int> queue;

  queue.push(start);
  visited[start] = true;
  while (!queue.empty()) {
    int next = queue.front(); queue.pop();
    for (int i : A[next]) {
      if (!visited[i]) {
        answer[i]++;
        queue.push(i);
        visited[i] = true;
      }
    }
  }
}

int main() {
  long long n, m;
  std::cin >> n >> m;
  A.resize(n + 1);
  answer.resize(n + 1);

  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    A[a].push_back(b);
  }

  visited.resize(n + 1);

  for (int i = 0; i <= n; ++i) {
    std::fill(visited.begin(), visited.end(), false);
    BFS(i);
  }

  int maxValue = 0;
  for (int i = 1; i <= n; ++i) {
    maxValue = std::max(maxValue, answer[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (answer[i] == maxValue) {
      std::cout << i << " ";
    }
  }
  return (0);
}