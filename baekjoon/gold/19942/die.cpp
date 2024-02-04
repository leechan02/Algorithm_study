#include <iostream>
#include <vector>

int ans = 987654321;
int n, mp, mf, ms, mv;
struct food {
  int p, f, s, v, c;
} list[16];
std::vector<int> tmp;
std::vector<int> order;

bool check() {
  int a = 0, b = 0, c = 0, d = 0;
  for (auto i : tmp) {
    a += list[i].p;
    b += list[i].f;
    c += list[i].s;
    d += list[i].v;
  }
  if (a >= mp && b >= mf && c >= ms && d >= mv) {
    return true;
  }
  return false;
}

void combi(int start) {
  if (check()) {
    int cost = 0;
    for (auto i : tmp) {
      cost += list[i].c;
    }
    if (cost < ans) {
      ans = cost;
      order = tmp;
    }
  }
  for (int i = start; i < n; ++i) {
    tmp.push_back(i);
    combi(i + 1);
    tmp.pop_back();
  }
}

int main() {
  std::cin >> n;
  std::cin >> mp >> mf >> ms >> mv;
  for (int i = 0; i < n; ++i) {
    std::cin >> list[i].p >> list[i].f >> list[i].s >> list[i].v >> list[i].c;
  }
  combi(0);
  if (order.empty()) {
    std::cout << "-1\n";
  } else {
    std::cout << ans << "\n";
    for (auto i : order) {
      std::cout << i + 1 << " ";
    }
  }
}