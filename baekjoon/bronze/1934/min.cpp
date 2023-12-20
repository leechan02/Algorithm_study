#include <iostream>

int gcd(int a, int b) {
  int c = a % b;
  if (c == 0) {
    return b;
  }
  return (gcd(b, c));
}

int main() {
  int T, A, B;
  std::cin >> T;
  for (int i = 0; i < T; ++i) {
    std::cin >> A >> B;
    int tmp;
    if (A > B) {
      tmp = gcd(A, B);
    } else {
      tmp = gcd(B, A);
    }
    std::cout << A * B / tmp << '\n';
  }
  return (0);
}