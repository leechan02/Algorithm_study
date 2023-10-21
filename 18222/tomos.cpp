#include <iostream>

bool x = 0;
unsigned long long filp = 1;

bool recursive(unsigned long long k) {
  if (k == 1) { 
    return x;
  }
  filp = 1;
  while ((filp << 1) < k) {
    filp <<= 1;
  }
  return !recursive(k - filp);
}

int main() {
  unsigned long long k;

  std::cin >> k;

  std::cout << recursive(k) << std::endl;
  return 0;
}
// 0 1 10 1001 10010110 1001011001101001
// 1 2  4    8       16               32