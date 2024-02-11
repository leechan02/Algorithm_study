#include <iostream>
#include <cmath>
#include <algorithm>

typedef long long ll;
ll n, attack, t, a, h, hp, mx, damage;

int main() {
  std::cin >> n >> attack;
  while (n--) {
    std::cin >> t >> a >> h;
    if (t == 1) {
      damage = a * (ceil((double)h / attack) - 1);
      if (hp < damage) {
        mx += damage - hp;
        hp = 0;
      } else hp -= damage;
    } else {
      attack += a;
      hp = std::min(hp + h, mx);
    }
  }
  std::cout << mx + 1 << "\n";
}