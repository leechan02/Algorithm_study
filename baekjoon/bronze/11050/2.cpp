#include <iostream>

int fac(int a) {
  if (a == 1 || a == 0) {
    return 1;
  }
  return a * fac(a - 1);
}

int main() {
  int n, k;
  std::cin >> n >> k;

  int choose = 1;
  for (int i = 0; i < k; ++i) {
    choose *= n;
    --n;
  }

  std::cout << choose / fac(k) << "\n";
}