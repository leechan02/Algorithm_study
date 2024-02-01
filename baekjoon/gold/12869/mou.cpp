#include <algorithm>
#include <iostream>
#include <queue>

int n, hp[3], visited[64][64][64];
int com[6][3]{{9, 3, 1}, {9, 1, 3}, {3, 1, 9}, {3, 9, 1}, {1, 3, 9}, {1, 9, 3}};
struct scv {
  int a, b, c;
};

int solve(int a, int b, int c) {
  std::queue<scv> q;
  visited[a][b][c] = 1;
  q.push({a, b, c});
  while (!q.empty()) {
    int a = q.front().a;
    int b = q.front().b;
    int c = q.front().c;
    q.pop();
    for (int i = 0; i < 6; ++i) {
      int na = std::max(0, a - com[i][0]);
      int nb = std::max(0, b - com[i][1]);
      int nc = std::max(0, c - com[i][2]);
      if (visited[na][nb][nc] != 0)
        continue;
      visited[na][nb][nc] = visited[a][b][c] + 1;
      q.push({na, nb, nc});
    }
  }
  return visited[0][0][0] - 1;
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> hp[i];
  }
  std::cout << solve(hp[0], hp[1], hp[2]) << "\n";
}