#include <iostream>

int main() {
  int h, m;
  std::cin >> h >> m;

  int time = h * 60 + m;
  if (time < 45) {
    time += 24 * 60;
  }
  time -= 45;
  std::cout << time / 60 << " " << time % 60 << "\n";
}