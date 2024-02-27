#include <iostream>
#include <cmath>

int size, y, x;
char map[101][101];
std::string str, ans;

int main() {
  std::cin >> str;
  size = str.size();
  y = 1, x = size;
  for (int i = 1; i <= std::sqrt(size); ++i) {
    for (int j = i; j <= size; ++j) {
      if (i * j == size) y = i, x = j;
    }
  }

  int s = 0;
  for (int j = 0; j < x; ++j) {
    for (int i = 0; i < y; ++i) {
      map[i][j] = str[s++];
    }
  }

  for (int i = 0; i < y; ++i) {
    for (int j = 0; j <x; ++j) {
      ans += map[i][j];
    }
  }
  std::cout << ans << "\n";
}