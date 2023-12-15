#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> tree[100001];
std::vector<int> distance;

void BFS(int from) {
  std::queue<int> queue;
  bool visited[100001] = {0, };

  queue.push(from);
  visited[from] = true;
  while (!queue.empty()) {
    int now = queue.front();
    queue.pop();
    for (int i = 0; i < tree[now].size(); ++i) {
      if (visited[tree[now][i].first] == false) {
        queue.push(tree[now][i].first);
        visited[tree[now][i].first] = true;
        distance[tree[now][i].first] = distance[now] + tree[now][i].second;
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int V, to, from = 0, len = 0;
  std::cin >> V;

  for (int i = 0; i < V; ++i) {
    std::cin >> to;
    while (true) {
      std::cin >> from;
      if (from == -1) {
        break;
      }
      std::cin >> len;
      tree[from].push_back(std::make_pair(to, len));
      tree[to].push_back(std::make_pair(from, len));
    }
  }

  distance = std::vector<int>(V + 1, 0);
  BFS(1);
  auto max = std::max_element(distance.begin(), distance.end());
  int next = std::distance(distance.begin(), max);
  std::fill(distance.begin(), distance.end(), 0);
  BFS(next);
  auto ans = std::max_element(distance.begin(), distance.end());
  std::cout << *ans << '\n';
  return (0);
}

// 1 - (2) - 3 - (2) - 6
//           |
//          (3)
//           |
// 2 - (1) - 4 - (6) - 5