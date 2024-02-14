#include <iostream>
#include <queue>

int n, k, l, t, second, die, dir = 1, hy, hx;
char where;
int map[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
std::queue<std::pair<int, int>> snake;
std::vector<std::pair<int, int>> play;

int until(int cnt, char where) {
  while (cnt--) {
    ++second;
    int ny = hy + dy[dir];
    int nx = hx + dx[dir];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == 1) return 1;
    if (map[ny][nx] != 2) {
      map[snake.front().first][snake.front().second] = 0;
      snake.pop();
    }
    map[ny][nx] = 1, hy = ny, hx = nx;
    snake.push({hy, hx});
  }
  if (where == 'D') dir = (dir + 1) % 4;
  else dir = (dir + 3) % 4;
  return 0;
}

int main() {
  std::cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int y, x;
    std::cin >> y >> x;
    map[y - 1][x - 1] = 2;
  }
  std::cin >> l;
  map[0][0] = 1;
  snake.push({0, 0});
  for (int i = 0; i < l; ++i) {
    std::cin >> t >> where;
    play.push_back({t, where});
  }
  for (auto i : play) {
    die = until(i.first - second, i.second);
    if (die != 0) break;
  }
  if (die == 0) until(10000, 'D');
  std::cout << second << "\n";
}