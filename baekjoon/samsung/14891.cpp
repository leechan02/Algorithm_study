#include <iostream>
#include <vector>
#include <algorithm>

int k, which, d, nd, ans;
std::vector<int> chain[5];
std::vector<std::pair<int, int>> list;

void check(int i, int d) {
  nd = d;
  for (int right = i + 1; right <= 4; ++right) {
    if (chain[right - 1][2] == chain[right][6]) break;
    nd = (nd == 1) ? -1 : 1;
    list.push_back({right, nd});
  }
  nd = d;
  for (int left = i - 1; left >= 1; --left) {
    if (chain[left + 1][6] == chain[left][2]) break;
    nd = (nd == 1) ? -1 : 1;
    list.push_back({left, nd});
  }
}

void move(int idx, int d) {
  list.push_back({idx, d});
  check(idx, d);
  for (auto i : list) {
    if (i.second == 1) {
      rotate(chain[i.first].rbegin(), chain[i.first].rbegin() + 1, chain[i.first].rend());
    } else {
      rotate(chain[i.first].begin(), chain[i.first].begin() + 1, chain[i.first].end());
    }
  }
  list.clear();
}

void point() {
  ans += (chain[1][0] == 0) ? 0 : 1;
  ans += (chain[2][0] == 0) ? 0 : 2;
  ans += (chain[3][0] == 0) ? 0 : 4;
  ans += (chain[4][0] == 0) ? 0 : 8;
}

int main() {
  std::string tmp;
  for (int i = 1; i <= 4; ++i) {
    std::cin >> tmp;
    for (int j = 0; j < 8; ++j) {
      chain[i].push_back(tmp[j] - '0');
    }
  }
  std::cin >> k;
  while (k--) {
    std::cin >> which >> d;
    move(which, d);
  }
  point();
  std::cout << ans << "\n";
}