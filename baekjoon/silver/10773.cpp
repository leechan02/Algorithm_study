#include <iostream>
#include <stack>

int k, tmp, result;
std::stack<int> money;

int main() {
  std::cin >> k;

  while (k--) {
    std::cin >> tmp;
    if (tmp != 0) {
      money.push(tmp);
    } else {
      money.pop();
    }
  }

  while (!money.empty()) {
    result += money.top();
    money.pop();
  }

  std::cout << result << "\n";
}