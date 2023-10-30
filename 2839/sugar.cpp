#include <iostream>
#include <limits.h>

long long arr[5000] = {
    0,
};

long long recursive(int n) {
  if (n == 0) {
    return 0;
  } else if (n < 0) {
    return INT_MAX;
  }
  if (arr[n] != 0) {
    return arr[n];
  }
  arr[n] = recursive(n - 3) + 1;
  arr[n] = std::min(arr[n], recursive(n - 5) + 1);
  return arr[n];
}

int main() {
  int N;

  std::cin >> N;

  long long result = recursive(N);
  if (result >= INT_MAX) {
    result = -1;
  }
  std::cout << result;
  return (0);
}