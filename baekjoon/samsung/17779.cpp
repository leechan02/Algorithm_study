#include <iostream>
#include <vector>

int n, min = 1e9;
int map[21][21];
int tmp[21][21];

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
    }
  }
}