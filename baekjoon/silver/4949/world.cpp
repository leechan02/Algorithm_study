#include <iostream>
#include <stack>

int main() {
  while (true) {
    std::string str;
    std::getline(std::cin, str);
    if (str == ".") {
      break;
    }
    std::string balance;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] == ')') {
        balance += str[i];
      }
    }

    std::stack<char> stack;
    for (int i = 0; i < balance.size(); ++i) {
      if (stack.empty()) {
        stack.push(balance[i]);
      } else if ((stack.top() == '(' && balance[i] == ')') ||
                 (stack.top() == '[' && balance[i] == ']')) {
        stack.pop();
      } else {
        stack.push(balance[i]);
      }
    }
    if (stack.empty()) {
      std::cout << "yes\n";
    } else {
      std::cout << "no\n";
    }
  }
}