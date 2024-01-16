#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;

  int j;
  std::cin >> j;

  int move = 0, basketStart = 1, basketEnd = m, apple;
  while (j--) {
    std::cin >> apple;

    while (apple > basketEnd) {
      ++basketEnd;
      ++basketStart;
      ++move;
    }
    while (apple < basketStart) {
      --basketEnd;
      --basketStart;
      ++move;
    }
  }
  std::cout << move << "\n";
}