#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> arr[n + 1];
  std::vector<int> D(n + 1, 0);
  std::vector<int> T(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    int time, num;
    std::cin >> time >> num;
    T[i] = time;
    while (num > 0) {
      arr[num].push_back(i);
      D[i]++;
      std::cin >> num;
    }
  }

  std::queue<int> queue;
  for (int i = 1; i <= n; ++i) {
    if (D[i] == 0) {
      queue.push(i);
    }
  }

  std::vector<int> res(n + 1, 0);
  while (!queue.empty()) {
    int now = queue.front();
    queue.pop();

    for (int next : arr[now]) {
      --D[next];
      res[next] = std::max(res[next], res[now] + T[now]);
      if (D[next] == 0) {
        queue.push(next);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    std::cout << res[i] + T[i] << '\n';
  }
  return (0);
}