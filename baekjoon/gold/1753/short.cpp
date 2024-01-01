#include <climits>
#include <iostream>
#include <queue>
#include <vector>

typedef std::pair<int, int> Node;
std::vector<Node> graph[20001];
std::vector<int> D;

void dijkstra(int start) {
  std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
  pq.push(std::make_pair(0, start));

  while (!pq.empty()) {
    const Node &now = pq.top();

    int from = now.second;
    int cur_dist = now.first;
    if (cur_dist == D[from]) {
      for (auto edge : graph[from]) {
        int &next = edge.first;
        int &weight = edge.second;

        int next_dist = D[from] + weight;
        if (D[next] > next_dist) {
          D[next] = next_dist;
          pq.push(std::make_pair(D[next], next));
        }
      }
    }
    pq.pop();
  }
}

int main() {
  int v, e, k;
  std::cin >> v >> e >> k;

  for (int i = 0; i < e; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    graph[u].push_back(std::make_pair(v, w));
  }

  D = std::vector<int>(v + 1, INT_MAX);
  D[k] = 0;
  dijkstra(k);
  for (int i = 1; i <= v; ++i) {
    if (D[i] == INT_MAX) {
      std::cout << "INF\n";
    } else {
      std::cout << D[i] << '\n';
    }
  }
  return (0);
}