#include <iostream>
#include <deque>
#include <algorithm>

int n, m, p, res, left, right;
std::deque<int> dq;

int main() {
  std::cin >> n >> m;

  for (int i = 1; i <= n; ++i) dq.push_back(i);

  for (int i = 0; i < m; ++i) {
    std::cin >> p;

    left = 0, right = 1;
    for (auto it = dq.begin(); it != dq.end(); ++it) {
      if (*it == p) break;
      ++left;
    }

    for (auto it = dq.end(); it != dq.begin(); --it) {
      if (it == dq.end()) continue;
      if (*it == p) break;
      ++right;
    }

    if (left <= right) {
      res += left;
      std::rotate(dq.begin(), dq.begin() + left, dq.end());
    } else {
      res += right;
      std::rotate(dq.rbegin(), dq.rbegin() + right, dq.rend());
    }
    dq.pop_front();
  }

  std::cout << res << "\n";
}