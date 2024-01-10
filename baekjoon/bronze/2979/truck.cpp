#include <iostream>
#include <vector>

int times[101];

int main() {
  int price[3];
  for (int &p : price) {
    std::cin >> p;
  }

  std::vector<std::pair<int, int>> trucks;
  for (int i = 0; i < 3; ++i) {
    int from, to;
    std::cin >> from >> to;
    trucks.push_back({from, to});

    for (int i = from; i < to; ++i) {
      ++times[i];
    }
  }

  int sum = 0;
  for (auto truck : trucks) {
    for (int i = truck.first; i < truck.second; ++i) {
      sum += price[times[i] - 1];
    }
  }

  std::cout << sum << "\n";
}