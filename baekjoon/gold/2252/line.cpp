#include <iostream>
#include <vector>
#include <queue>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> arr[n + 1];
  std::vector<int> D(n + 1, 0);

  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    arr[a].push_back(b);
    D[b]++;
  }
  std::queue<int> queue;

  for (int i = 1; i <= n; ++i) {
    if (D[i] == 0) {
      queue.push(i);
    }
  }

  while (!queue.empty()) {
    int now = queue.front();
    queue.pop();
    std::cout << now << " ";
    for (int next : arr[now]) {
      --D[next];
      if (D[next] == 0) {
        queue.push(next);
      }
    }
  }
}