#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int D[n + 1][n + 1];
  for (int s = 1; s <= n; ++s) {
    for (int e = 1; e <= n; ++e) {
      std::cin >> D[s][e];
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int s = 1; s <= n; ++s) {
      for (int e = 1; e <= n; ++e) {
        if (D[s][k] == 1 && D[k][e]) {
          D[s][e] = 1;
        }
      }
    }
  }

  for (int s = 1; s <= n; ++s) {
    for (int e = 1; e <= n; ++e) {
      std::cout <<  D[s][e] << " ";
    }
    std::cout << "\n";
  }
}