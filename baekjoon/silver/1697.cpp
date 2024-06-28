#include <iostream>
#include <queue>

int n, k, cur;
int dist[100002];

void bfs() {
  std::queue<int> q;
  dist[n] = 1;
  q.push(n);

  while (dist[k] == 0) {
    cur = q.front(); q.pop();

    for (int next : {cur + 1, cur - 1, cur * 2}) {
      if (next < 0 || next > 100000 || dist[next] != 0) continue;
      dist[next] = dist[cur] + 1;
      q.push(next);
    }
  }
}

int main() {
  std::cin >> n >> k;

  bfs();

  std::cout << dist[k] - 1<< "\n";
}