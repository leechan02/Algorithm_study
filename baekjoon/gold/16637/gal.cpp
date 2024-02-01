#include <algorithm>
#include <iostream>
#include <vector>

int n, ans = -987654321;
std::string start;
std::vector<int> num;
std::vector<char> oper;

int op(char a, int b, int c) {
  if (a == '+') return (b + c);
  if (a == '-') return (b - c);
  if (a == '*') return (b * c);
}

void dfs(int here, int n) {
  if (here == num.size() - 1) {
    ans = std::max(ans, n);
    return;
  }
  dfs(here + 1, op(oper[here], n, num[here + 1]));

  if (here + 2 <= num.size() - 1) {
    int tmp = op(oper[here + 1], num[here + 1], num[here + 2]);
    dfs(here + 2, op(oper[here], n, tmp));
  }
}

int main() {
  std::cin >> n >> start;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      oper.push_back(start[i]);
    } else {
      num.push_back(start[i] - '0');
    }
  }

  dfs(0, num[0]);
  std::cout << ans << "\n";
}