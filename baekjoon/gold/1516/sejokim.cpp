#include <iostream>
#include <vector>

std::vector<int> T;
std::vector<int> arr[501];
std::vector<int> dp(501, 0);
std::vector<bool> visited(501, false);
int max = 0;

void DFS(int index, int sum) {
  if (arr[index].size() == 0) {
    if (sum > max) {
      max = sum;
    }
    return;
  }

  visited[index] = true;
  for (int i : arr[index]) {
    if (!visited[i]) {
      DFS(i, sum + T[i]);
    }
  }
  visited[index] = false;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;

  T = std::vector<int>(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    int time, num;
    std::cin >> time >> num;
    T[i] = time;
    while (num > 0) {
      arr[i].push_back(num);
      std::cin >> num;
    }
  }

  for (int i = 1; i <= n; ++i) {
    visited.assign(501, false);
    max = 0;
    DFS(i, T[i]);
    std::cout << max << '\n';
  }
  return (0);
}