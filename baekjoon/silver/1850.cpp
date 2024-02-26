#include <iostream>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
  unsigned long long c = a % b;
  if (c == 0) {
    return b;
  }
  return (gcd(b, c));
}

int main() {
  unsigned long long a, b;
  std::cin >> a >> b;

  unsigned long long res;
  if (a > b) {
    res = gcd(a, b);
  } else {
    res = gcd(b, a);
  }
  while (res--) {
    std::cout << "1";
  }
  return (0);
}