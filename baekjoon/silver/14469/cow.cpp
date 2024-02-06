#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> vector;
  for (int i = 0; i < n; ++i) {
    int arrived, in;
    std::cin >> arrived >> in;
    vector.push_back({arrived, in});
  }
  std::sort(vector.begin(), vector.end());
  int time = vector[0].first + vector[0].second;
  for (int i = 1; i < n; ++i) {
    if (vector[i].first < time) {
      time += vector[i].second;
    } else {
      time = vector[i].first + vector[i].second;
    }
  }
  std::cout << time << "\n";
}