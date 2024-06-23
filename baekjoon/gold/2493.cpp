#include <iostream>
#include <stack>
#include <vector>

int n, num, max, cur;
std::vector<int> vector;
std::stack<int> stack;

int main() {
  std::ios_base::sync_with_stdio(0), std::cin.tie(0);

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    vector.push_back(num);
  }

  std::vector<int> res(n, 0);
  for (int i = 0; i < n; ++i) {
    while (!stack.empty() && vector[stack.top()] <= vector[i])
      stack.pop();

    if (!stack.empty())
      res[i] = stack.top() + 1;

    stack.push(i);
  }

  for (int i = 0; i < n; ++i) {
    std::cout << res[i] << " ";
  }
}