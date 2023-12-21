#include <iostream>
#include <vector>
#include <queue>

std::vector<int> node[300001];
bool visited[300001];

void BFS(int start, int end, int city) {
  std::queue<int> queue;
  std::vector<int> dis(300001, 0);

  visited[start] = true;
  queue.push(start);
  while (!queue.empty()) {
    int next = queue.front();
    queue.pop();
    for (int i = 0; i < node[next].size(); ++i) {
      if (!visited[node[next][i]]) {
        dis[node[next][i]] = dis[next] + 1;
        visited[node[next][i]] = true;
        queue.push(node[next][i]);
      }
    }
  }

  bool res = false;
  for (int i = 1; i <= city; ++i) {
    if (dis[i] == end) {
      res = true;
      std::cout << i << '\n';
    }
  }
  if (!res) {
    std::cout << "-1" << '\n';
  }
}

int main() {
  int n, m, k, x;
  std::cin >> n >> m >> k >> x;

  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;

    node[a].push_back(b);
  }

  BFS(x, k, n);

  return (0);
}
