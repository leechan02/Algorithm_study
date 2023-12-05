#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

struct compare {
  bool operator()(int o1, int o2) {
    int firstAbs = std::abs(o1);
    int secondAbs = std::abs(o2);
    if (firstAbs == secondAbs) {
      return o1 > o2;
    } else {
      return firstAbs > secondAbs;
    }
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N;
  std::cin >> N;

  std::priority_queue<int, std::vector<int>, compare> queue;
  for (int i = 0; i < N; ++i) {
    int request;
    std::cin >> request;

    if (request == 0) {
      if (queue.empty()) {
        std::cout << "0\n";
      } else {
        std::cout << queue.top() << '\n';
        queue.pop();
      }
    } else {
      queue.push(request);
    }
  }
  return (0);
}