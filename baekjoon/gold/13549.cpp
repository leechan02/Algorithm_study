#include <iostream>
#include <queue>

int n, k;
int map[100001];

void bfs() {
  std::queue<int> q;
  q.push(n);
  map[n] = 1;

  while (!q.empty()) {
    int cur = q.front(); q.pop();

    for (auto i : {cur * 2, cur - 1, cur + 1}) {
      if (i < 0 || i > 100000 || map[i] != 0) continue;
      if (i == cur * 2) {
        map[i] = map[cur];
      } else {
        map[i] = map[cur] + 1;
      }
      q.push(i);
    }
  }
}

int main() {
  std::cin >> n >> k;

  bfs();

  std::cout << map[k] - 1 << "\n";
}