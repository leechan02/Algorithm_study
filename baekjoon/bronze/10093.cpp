#include <iostream>

long long a, b, big, small;

int main() {
  std::cin >> a >> b;
  if (a > b) {
    big = a, small = b;
  } else if (b > a) {
    big = b, small = a;
  } else {
    std::cout << "0\n";
    return 0;
  }

  std::cout << big - small - 1 << "\n";
  for (long long i = small + 1; i < big; ++i) {
    std::cout << i << " ";
  }
}