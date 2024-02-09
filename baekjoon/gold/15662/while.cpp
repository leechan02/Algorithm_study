#include <iostream>
#include <vector>

int t, k;
std::vector<int> gear[1001];

void rotating(int i, int dir) {
  std::cout << "before: ";
  for (auto i : gear[i]) {
    std::cout << i << " ";
  }
  std::cout << "\n";
  if (dir == 1) {
    rotate(gear[i].rbegin(), gear[i].rbegin() + 1, gear[i].rend());
  } else {
    rotate(gear[i].begin(), gear[i].begin() + 1, gear[i].end());
  }
  std::cout << "after: ";
  for (auto i : gear[i]) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}

void moving(int i, int dir) {
  rotating(i - 1, dir);

  int tmp = dir;
  for (int toe = i + 1; toe <= t; ++toe) {
    std::cout << "toe: " << toe << "\n";
    if (gear[toe - 2][2] != gear[toe - 1][6]) {
      std::cout << "right\n";
      if (tmp == 1) tmp = -1;
      else tmp = 1;
      rotating(toe - 1, tmp);
    } else break;
  }
  tmp = dir;
  for (int tos = i - 1; tos > 0; --tos) {
    std::cout << "tos: " << tos << "\n";
    if (gear[tos][6] != gear[tos - 1][2]) {
      std::cout << "left\n";
      if (tmp == 1) tmp = -1;
      else tmp = 1;
      rotating(tos - 1, tmp);
    } else break;
  }
}

int main() {
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    gear[i] = std::vector<int>(8);
    std::string tmp;
    std::cin >> tmp;
    for (int j = 0; j < 8; ++j) {
      gear[i][j] = (tmp[j] - '0');
    }
  }

  std::cin >> k;
  while (k--) {
    int i, dir;
    std::cin >> i >> dir;
    moving(i, dir);
  }

  int ans = 0;
  for (int i = 0; i < t; ++i) {
    if (gear[i][0] == 1) {
      ++ans;
    }
  }

  std::cout << ans << "\n";
}