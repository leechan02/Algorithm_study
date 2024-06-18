#include <iostream>
#include <string>

std::string result = "EABCD";

int main() {
  for (int i = 0; i < 3; ++i) {
    int n = 0, tmp = 0;
    for (int j = 0; j < 4; ++j) {
      std::cin >> tmp;
      if (tmp == 0) ++n;
    }
    std::cout << result[n] << "\n";
  }
}