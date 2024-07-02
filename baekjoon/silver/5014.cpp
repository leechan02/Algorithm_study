#include <iostream>
#include <queue>

int f, s, g, u, d;
int dist[1000002];

void bfs(int from) {
  std::queue<int> q;
  q.push(from);
  dist[from] = 1;

  while (!q.empty()) {
    int cur = q.front(); q.pop();

    for (auto i : {cur + u, cur - d}) {
      if (i < 1 || i > f || dist[i]) continue;
      q.push(i);
      dist[i] = dist[cur] + 1;
    }
  }
}

int main() {
  std::cin >> f >> s >> g >> u >> d;

  bfs(s);

  if (dist[g] == 0) std::cout << "use the stairs\n";
  else std::cout << dist[g] - 1 << "\n";
}