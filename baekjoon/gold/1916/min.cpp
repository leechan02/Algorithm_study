#include <iostream>
#include <vector>
#include <climits>
#include <queue>

typedef std::pair<int, int> Node;
std::vector<Node> graph[10001];
std::vector<int> res(10001, INT_MAX);

void dijkstra(int start) {
  std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
  pq.push(std::make_pair(0, start));

  while (!pq.empty()) {
    Node from = pq.top();
    pq.pop();
    if (res[from.second] < from.first) {
      continue;
    }

    for (auto to : graph[from.second]) {
      int distance = res[from.second] + to.second;
      if (res[to.first] > distance) {
        res[to.first] = distance;
        pq.push(std::make_pair(res[to.first], to.first));
      }
    }
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int from, to, pee;
    std::cin >> from >> to >> pee;
    graph[from].push_back(std::make_pair(to, pee));
  }
  int departures, arrivals;
  std::cin >> departures >> arrivals;
  res[departures] = 0;
  dijkstra(departures);
  std::cout << res[arrivals] << '\n';
  return (0);
}