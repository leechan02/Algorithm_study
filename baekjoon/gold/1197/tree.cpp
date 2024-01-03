#include <iostream>
#include <vector>
#include <queue>

std::vector<int> parent;

typedef struct edge {
  int s, e, v;
  bool operator > (const edge& temp) const {
    return v > temp.v;
  }
} edge;

int find(int a) {
  if (a == parent[a]) {
    return a;
  } else {
    return parent[a] = find(parent[a]);
  }
}

void findunion(int a, int b) {
  a = find(a);
  b = find(b);

  if (a != b) {
    parent[b] = a;
  }
}

int main() {
  int v, e;
  std::cin >> v >> e;

  parent.resize(v + 1);
  for (int i = 1; i <= v; ++i) {
    parent[i] = i;
  }

  std::priority_queue<edge, std::vector<edge>, std::greater<edge>> pq;
  for (int i = 0; i < e; ++i) {
    int s, e, v;
    std::cin >> s >> e >> v;
    pq.push(edge{s, e, v});
  }

  int useEdge = 0, result = 0;
  while (useEdge < v - 1) {
    edge now = pq.top();
    pq.pop();

    if (find(now.s) != find(now.e)) {
      findunion(now.s, now.e);
      result = result + now.v;
      ++useEdge;
    }
  }
  std::cout << result << "\n";
}