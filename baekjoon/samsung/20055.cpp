#include <iostream>
#include <vector>
#include <algorithm>

int n, k, w, level;
struct pos{
  int hp, robot;
};
std::vector<pos> belt;

bool hpCheck() {
  int cnt = 0;
  for (auto t : belt) {
    if (t.hp == 0) ++cnt;
  }
  if (cnt >= k) return true;
  return false;
}

void moveRobot() {
  for (int i = n - 2; i >= 0; --i) {
    if (belt[i].robot == 0 || belt[i + 1].hp == 0 || belt[i + 1].robot == 1) continue;
    belt[i].robot = 0; belt[i + 1].robot = 1, belt[i + 1].hp--;
    if (i + 1 == n - 1) belt[i + 1].robot = 0;
  }
}

int main() {
  std::cin >> n >> k;
  for (int i = 0; i < 2 * n; ++i) {
    std::cin >> w;
    belt.push_back({w, 0});
  }
  while (true) {
    ++level;
    rotate(belt.rbegin(), belt.rbegin() + 1, belt.rend());
    if (belt[n - 1].robot == 1) belt[n - 1].robot = 0;
    moveRobot();
    if (belt[0].hp != 0) {
      belt[0].robot = 1;
      belt[0].hp--;
    }
    if (hpCheck()) break;
  }
  std::cout << level << "\n";
}