#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

struct order {
  int cnt = 0;
  int pos = -1;
};

bool cmp(const std::pair<int, order>& a, const std::pair<int, order>& b) {
  if (a.second.cnt == b.second.cnt) {
    return (a.second.pos < b.second.pos);
  }
  return (a.second.cnt > b.second.cnt);
}

int main() {
  int n, c;
  std::cin >> n >> c;

  std::unordered_map<int, order> map;
  for (int i = 0; i < n; ++i) {
    int tmp;
    std::cin >> tmp;

    map[tmp].cnt++;
    if (map[tmp].pos == -1) {
      map[tmp].pos = i;
    }
  }

  std::vector<std::pair<int, order>> arr;
  for (auto i : map) {
    arr.push_back({i.first, i.second});
  }

  std::sort(arr.begin(), arr.end(), cmp);
  for (auto i : arr) {
    for (int ii = 0; ii < i.second.cnt; ++ii) {
      std::cout << i.first << " ";
    }
  }
}