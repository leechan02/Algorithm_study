#include <algorithm>
#include <iostream>
#include <vector>

int n;
char op[10];
bool visited[10];
std::vector<std::string> com;

bool check(char a, char b, char boo) {
  if (a < b && boo == '<') return true;
  if (a > b && boo == '>') return true;
  return false;
}

void dfs(int idx, std::string num) {
  if (idx == n + 1) {
    com.push_back(num);
    return;
  }
  for (int i = 0; i <= 9; ++i) {
    if (visited[i]) continue;
    if (idx == 0 || check(num[idx - 1], i + '0', op[idx - 1])) {
      visited[i] = true;
      dfs(idx + 1, num + std::to_string(i));
      visited[i] = false;
    }
  }
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> op[i];
  }
  dfs(0, "");
  std::sort(com.begin(), com.end());
  std::cout << com[com.size() - 1] << "\n" << com[0] << "\n";
}