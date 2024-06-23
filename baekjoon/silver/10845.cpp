#include <iostream>
#include <queue>
#include <string>

int n;
std::queue<int> q;
std::string com;

int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n;

  while (n--) {
    std::cin >> com;

    if (com == "push") {
      int x;
      std::cin >> x;

      q.push(x);
    } else if (com == "pop") {
      if (q.empty()) {
        std::cout << "-1\n";
      } else {
        std::cout << q.front() << "\n";
        q.pop();
      }
    } else if (com == "size") {
      if (q.empty())
        std::cout << "0\n";
      else
        std::cout << q.size() << "\n";
    } else if (com == "empty") {
      if (q.empty())
        std::cout << "1\n";
      else
        std::cout << "0\n";
    } else if (com == "front") {
      if (q.empty())
        std::cout << "-1\n";
      else
        std::cout << q.front() << "\n";
    } else if (com == "back") {
      if (q.empty())
        std::cout << "-1\n";
      else
        std::cout << q.back() << "\n";
    }
  }
}