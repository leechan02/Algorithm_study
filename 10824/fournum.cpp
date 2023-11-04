#include <iostream>

int main() {
  std::string A, B, C, D;

  std::cin >> A >> B >> C >> D;

  long long a, b;

  a = std::stoll(A + B);
  b = std::stoll(C + D);

  std::cout << a + b << std::endl;
  return 0;
}