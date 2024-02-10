#include <iostream>

int white[6] = {1, 1, 2, 2, 2, 8};
int com[6];

int main() {
  for (int i = 0; i < 6; ++i) {
    std::cin >> com[i];
  }

  for (int i = 0; i < 6; ++i) {
    if (white[i] == com[i]) {
      std::cout << "0 ";
    } else {
      std::cout << white[i] - com[i] << " ";
    }
  }
}