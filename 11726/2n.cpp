#include <iostream>

int arr[1000] = {
    0,
};

int recursive(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }
  if (arr[n] != 0) {
    return arr[n];
  }
  return (arr[n] = ((recursive(n - 1) % 10007) + (recursive(n - 2) % 10007)) %
                   10007);
}

int main() {
  int N;

  std::cin >> N;

  std::cout << recursive(N + 1);
  return 0;
}