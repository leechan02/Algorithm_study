#include <iostream>
#include <queue>

#define MAX 200000

int visited[MAX + 1];
long long cnt[MAX + 1];

int main() {
  int n, m;
  std::cin >> n >> m;
  if (n == m) {
    std::cout << "0\n" << "1\n";
    return 0;
  }

  visited[n] = 1;
  cnt[n] = 1;
  std::queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int next : {now - 1, now + 1, now * 2}) {
      if (0 <= next && next <= MAX) {
        if (visited[next] == false) {
          q.push(next);
          visited[next] = visited[now] + 1;
          cnt[next] += cnt[now];
        } else if (visited[next] == visited[now] + 1) {
          cnt[next] += cnt[now];
        }
      }
    }
  }
  std::cout << visited[m] - 1 << "\n";
  std::cout << cnt[m] << "\n";
}