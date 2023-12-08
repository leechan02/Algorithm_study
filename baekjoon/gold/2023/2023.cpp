#include <iostream>

static int N;

bool isPrime(int num) {
  if (num == 1) {
    return false;
  }
  for (int i = 2; i <= num / i; ++i) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

void DFS(int num, int digit = 0) {
  if (digit == N) {
    std::cout << num << '\n';
    return;
  }
  for (int i = 1; i < 10; ++i) {
    if (isPrime(num * 10 + i)) {
      DFS(num * 10 + i, digit + 1);
    }
  }
}

int main() {
  std::cin >> N;

  DFS(0);
  return (0);
}