#include <iostream>
#include <vector>

int ans;
std::vector<int> com[101];
bool visited[101];

void dfs(int start) {
  for (auto i : com[start]) {
    if (visited[i] == false) {
      ++ans;
      visited[i] = true;
      dfs(i);
    }
  }
}

int main() {
  int n, w;
  std::cin >> n >> w;
  for (int i = 0; i < w; ++i) {
    int a, b;
    std::cin >> a >> b;
    com[a].push_back(b);
    com[b].push_back(a);
  }
  visited[1] = true;
  dfs(1);
  std::cout << ans << "\n";
}