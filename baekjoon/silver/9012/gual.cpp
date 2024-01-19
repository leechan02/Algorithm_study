#include <iostream>
#include <stack>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    std::string vps;
    std::cin >> vps;

    std::stack<char> stack;
    for (int i = 0; i < vps.size(); ++i) {
      if (stack.empty()) {
        stack.push(vps[i]);
      } else if (vps[i] == ')' && stack.top() != vps[i]) {
        stack.pop();
      } else {
        stack.push(vps[i]);
      }
    }
    if (stack.empty()) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}