#include <iostream>
#include <queue>

int n, apple, l, ans;
int map[101][101];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int direc;
int y, x;
std::queue<std::pair<int, int>> body;

bool go(int time, char turn) {
  while (time--) {
    ++ans;
    int ny = y + dy[direc];
    int nx = x + dx[direc];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == 2)
      return 1;
    y = ny; x = nx;
    if (map[ny][nx] == 1) {
      body.push({y, x});
    } else {
      body.push({y, x});
      map[body.front().first][body.front().second] = 0;
      body.pop();
    }
    map[ny][nx] = 2;
  }
  if (turn == 'D') {
    direc = (direc + 1) % 4;
  } else {
    direc = (direc - 1) % 4;
    if (direc < 0) {
      direc = 3;
    }
  }
  return 0;
}

int main() {
  std::cin >> n >> apple;
  for (int i = 0; i < apple; ++i) {
    int y, x;
    std::cin >> y >> x;
    map[y - 1][x - 1] = 1;
  }
  std::cin >> l;
  std::vector<std::pair<int, char>> route(l);
  for (int i = 0; i < l; ++i) {
    std::cin >> route[i].first >> route[i].second;
  }
  map[0][0] = 2;
  body.push({0, 0});
  int before = 0, time, dead = 0;
  for (auto i : route) {
    time = i.first - before;
    if (go(time, i.second)) {
      dead = 1;
      break;
    }
    before = i.first;
  }
  if (!dead) {
    go(101, 'D');
  }
  std::cout << ans << "\n";
}