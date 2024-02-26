#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int decimal[2000001] {0, };
  for (int i = 2; i <= 2000000; ++i) {
    decimal[i] = i;
  }

  for (int i = 2; i * i <= 2000000; ++i) {
    if (decimal[i] == 0) {
      continue;
    }
    for (int j = i + i; j <= 2000000; j += i) {
      decimal[j] = 0;
    }
  }

  for (int i = N; i <= 2000000; ++i) {
    if (decimal[i] == 0) {
      continue;
    }
    std::string tmp = std::to_string(decimal[i]);
    int start = 0, end = tmp.size() - 1;
    bool find = true;
    while (start < end) {
      if (tmp[start++] != tmp[end--]) {
        find = false;
        break;
      }
    }
    if (find) {
      std::cout << decimal[i] << '\n';
      return (0);
    }
  }
  return (0);
}