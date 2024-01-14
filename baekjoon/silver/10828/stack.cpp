#include <iostream>
#include <stack>

int n;
std::string command;
std::stack<int> stack;

int main() {
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    std::cin >> command;
    if (command == "push") {
      int num;
      std::cin >> num;

      stack.push(num);
    } else if (command == "pop") {
      if (stack.empty()) {
        std::cout << "-1\n";
        continue;
      }
      int tmp = stack.top();
      stack.pop();

      std::cout << tmp << "\n";
    } else if (command == "size") {
      std::cout << stack.size() << "\n";
    } else if (command == "empty") {
      if (stack.empty()) {
        std::cout << "1\n";
      } else {
        std::cout << "0\n";
      }
    } else if (command == "top") {
      if (stack.empty()) {
        std::cout << "-1\n";
        continue;
      }
      std::cout << stack.top() << "\n";
    }
  }
  return (0);
}