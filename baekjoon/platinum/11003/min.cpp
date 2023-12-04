#include <iostream>
#include <deque>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, L;
  std::cin >> N >> L;

  typedef std::pair<int, int> Node;
  std::deque<Node>  deque;

  for (int i = 0; i < N; ++i) {
    int now;
    std::cin >> now;

    while (deque.size() && deque.back().first > now) {
      deque.pop_back();
    }
    deque.push_back(std::make_pair(now, i));

    if (deque.front().second <= i - L) {
      deque.pop_front();
    }
    std::cout << deque.front().first << " ";
  }
  return (0);
}
