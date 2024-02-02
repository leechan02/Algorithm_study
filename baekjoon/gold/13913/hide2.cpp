#include <iostream>
#include <queue>
#include <vector>

#define MAX 200004

int visited[MAX];
int trace[MAX];
std::queue<int> q;
std::vector<int> v;

int main() {
  int n, k;
  std::cin >> n >> k;

  visited[n] = 1;
  q.push(n);
  while (!q.empty()) {
    int now = q.front(); q.pop();

    for (int next : {now + 1, now - 1, now * 2}) {
      if (next >= 0 && next < MAX && visited[next] == false) {
        visited[next] = visited[now] + 1;
        trace[next] = now;
        q.push(next);
      }
    }
  }
  for (int i = k; i != n; i = trace[i]) {
    v.push_back(i);
  }
  v.push_back(n);
  std::cout << visited[k] - 1 << "\n";
  for (auto it = v.rbegin(); it != v.rend(); ++it) {
    std::cout << *it << " ";
  }
}