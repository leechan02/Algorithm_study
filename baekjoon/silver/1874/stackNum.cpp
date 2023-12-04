#include <iostream>
#include <stack>
#include <vector>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int n, num = 1;
  std::cin >> n;

  std::vector<int> A(n, 0);
  std::vector<char> result;

  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }

  std::stack<int> stack;
  bool final = true;

  for (int i = 0; i < A.size(); ++i) {
    int a = A[i];
    if (num <= a) {
      while (num <= a) {
        stack.push(num++);
        result.push_back('+');
      }
      stack.pop();
      result.push_back('-');
    } else {
      int b = stack.top();
      stack.pop();

      if (a < b) {
        std::cout << "NO\n";
        final = false;
        break;
      } else {
        result.push_back('-');
      }
    }
  }
  if (final) {
    for (int i = 0; i < result.size(); ++i) {
      std::cout << result[i] << '\n';
    }
  }
  return 0;
}