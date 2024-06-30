#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

struct pos {
  int y, x;
};

int t, l, ny, nx;
bool visited[301][301];
pos from, to;
std::vector<pos> dir = {{2, 1},   {1, 2},   {-1, 2}, {-2, 1},
                        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

int bfs() {
  std::queue<std::pair<pos, int>> q;
  q.push({from, 0});
  visited[from.y][from.x] = true;

  while (!q.empty()) {
    auto [cur, moves] = q.front();
    q.pop();

    if (cur.y == to.y && cur.x == to.x) {
      return moves;
    }

    for (auto d : dir) {
      ny = cur.y + d.y;
      nx = cur.x + d.x;
      if (ny < 0 || ny >= l || nx < 0 || nx >= l || visited[ny][nx]) continue;
      visited[ny][nx] = true;
      q.push({{ny, nx}, moves + 1});
    }
  }
  return -1; // should never reach here if there is a valid path
}

int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> t;

  while (t--) {
    std::cin >> l >> from.y >> from.x >> to.y >> to.x;

    memset(visited, 0, sizeof(visited));

    std::cout << bfs() << "\n";
  }
}