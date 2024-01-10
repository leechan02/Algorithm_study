#include <iostream>

int cnt[26];

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    std::string tmp;
    std::cin >> tmp;

    ++cnt[tmp[0] - 97];
  }

  int player = 0;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] >= 5) {
      std::cout << (char)(i + 97);
      ++player;
    }
  }
  if (player == 0) {
    std::cout << "PREDAJA\n";
  }
  return (0);
}