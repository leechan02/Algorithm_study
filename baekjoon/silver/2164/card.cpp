#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N;
  std::cin >> N;

  std::queue<int> queue;
  for (int i = 1; i <= N; ++i) {
    queue.push(i);
  }

  while (queue.size() > 1) {
    queue.pop();

    if (queue.size() != 1) {
      int tmp = queue.front();
      queue.pop();
      queue.push(tmp);
    }
  }
  std::cout << queue.front() << '\n';
  return (0);
}