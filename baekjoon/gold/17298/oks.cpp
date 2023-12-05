#include <iostream>
#include <stack>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> A(N, 0);
  std::vector<int> ans(N, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  std::stack<int> stack;
  stack.push(0);
  for (int i = 1; i < N; ++i) {
    while (!stack.empty() && A[stack.top()] < A[i]) {
      ans[stack.top()] = A[i];
      stack.pop();
    }
    stack.push(i);
  }
  while (!stack.empty()) {
    std::cout << "top: " << stack.top() << std::endl;
    ans[stack.top()] = -1;
    stack.pop();
  }
  for (int i = 0; i < N; ++i) {
    std::cout << ans[i] << " ";
  }
  return (0);
}