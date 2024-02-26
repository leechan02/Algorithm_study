#include <iostream>

long long recursive(int A, int B, int C) {
  if (B == 0) {
    return 1;
  } else if (B % 2) {
    return (recursive(A, B - 1, C) * A % C);
  }
  return (recursive(A, B / 2, C) * recursive(A, B / 2, C) % C);
}

int main() {
  int A, B, C;
  long long result;

  std::cin >> A >> B >> C;

  result = recursive(A, B, C);
  std::cout << result;
  return 0;
}

// (A ^ B) % C

// (((A ^ 4) % C) * (10 % C)) % C

// (((A ^ 2) % C) * ((10 ^ 2) % C)) % C

// (A % 12) * (A % 12) % 12