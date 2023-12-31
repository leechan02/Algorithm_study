#include <iostream>
#include <vector>
#include <climits>
#define idx first
#define weight second

typedef std::pair<int, int> edge;
std::vector<long long> D;
std::vector<edge> graph[501];

bool BellmanFord(int start, int n) {
  D[start] = 0;

  // n-1번의 반복으로 모든 간선을 완화
  for (int i = 0; i < n - 1; ++i) {
    for (int from = 1; from <= n; ++from) {
      for (auto to : graph[from]) {
        long long distance = D[from] + to.weight;
        if (D[from] != LLONG_MAX && D[to.idx] > distance) {
          D[to.idx] = distance;
        }
      }
    }
  }

  // 음수 사이클 체크
  for (int from = 1; from <= n; ++from) {
    for (auto to : graph[from]) {
      long long distance = D[from] + to.weight;
      if (D[from] != LLONG_MAX && D[to.idx] > distance) {
        return false; // 음수 사이클 발견
      }
    }
  }

  return true;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  D = std::vector<long long>(n + 1, LLONG_MAX);

  for (int i = 0; i < m; ++i) {
    int from, to, time;
    std::cin >> from >> to >> time;
    graph[from].push_back(std::make_pair(to, time));
  }
  if (BellmanFord(1, n)) {
    for (int i = 2; i <= n; ++i) {
      std::cout << ((D[i] == LLONG_MAX) ? -1 : D[i]) << "\n";
    }
  } else {
    std::cout << "-1\n";
  }
}
