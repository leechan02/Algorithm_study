#include <iostream>
#include <queue>
#include <vector>

std::vector<int> parent;

typedef struct edge {
  int s, e, v;
  bool operator > (const edge& temp) const {
    return v > temp.v;
  }
} edge;

int getLength(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 96;
  } else if (c >= 'A' && c <= 'Z') {
    return c - 38;
  } else {
    return 0;
  }
}

int find(int a) {
  if (a == parent[a]) {
    return a;
  } else {
    return parent[a] = find(parent[a]);
  }
}

void unionfunc(int a, int b) {
  a = find(a);
  b = find(b);

  if (a != b) {
    parent[b] = a;
  }
}

int main() {
  int n;
  std::cin >> n;

  parent.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
  }

  int sum = 0;
  std::priority_queue<edge, std::vector<edge>, std::greater<edge>> pq;
  for (int s = 1; s <= n; ++s) {
    std::string tmp;
    std::cin >> tmp;
    for (int e = 0; e < n; ++e) {
      int v = getLength(tmp[e]);
      if (v != 0 && s != e + 1) {
        pq.push(edge{s, e + 1, v});
      }
      sum += v;
    }
  }

  int useEdge = 0, result = 0;
  while (!pq.empty()) {
    edge now = pq.top();
    pq.pop();

    if (find(now.s) != find(now.e)) {
      unionfunc(now.s, now.e);
      result = result + now.v;
      ++useEdge;
    }
  }

  if (useEdge == n - 1) {
    std::cout << sum - result << "\n";
  } else {
    std::cout << "-1\n";
  }
}
