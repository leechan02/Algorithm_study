#include <iostream>
#include <stack>

int n, cnt;
std::string str;

int main() {
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    std::cin >> str;

    std::stack<char> stack;
    for (char c : str) {
      if (!stack.empty() && stack.top() == c) {
        stack.pop();
      } else {
        stack.push(c);
      }
    }
    if (stack.size() == 0) {
      ++cnt;
    }
  }
  std::cout << cnt << "\n";
  return (0);
}
