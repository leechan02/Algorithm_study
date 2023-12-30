#include <iostream>
#include <vector>
#include <queue>
#include <climits>

typedef std::pair<int, int> Node;
std::vector<Node> graph[1001];
std::vector<int> res;
std::vector<int> before;

void dijkstra(int start) {
  std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
  pq.push(std::make_pair(0, start));

  while (!pq.empty()) {
    Node from = pq.top();
    pq.pop();
    // if (res[from.second] < from.first) {
    //   continue;
    // }

    std::cout << "from: " << from.second << std::endl;
    for (auto to : graph[from.second]) {
      int distance = res[from.second] + to.second;
      std::cout << "to: " << to.first << " dis: " << distance << std::endl;
      if (res[to.first] > distance && before[to.first] < distance) {
        res[to.first] = distance;
        pq.push(std::make_pair(res[to.first], to.first));
      }
    }
    std::cout << "==========" << std::endl;
  }
}

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    graph[a].push_back(std::make_pair(b, c));
  }
  res = std::vector<int>(n + 1);
  before = std::vector<int>(n + 1, 0);
  while (k--) {
    res.assign(n + 1, INT_MAX);
    res[1] = 0;
    dijkstra(1);
    for (int i = 1; i <= n; ++i) {
      before[i] = res[i];
      std::cout << before[i] << ' ';
    }
    std::cout << std::endl;
  }
  for (int i = 1; i <= n; ++i) {
    std::cout << res[i] << '\n';
  }
  return (0);
}