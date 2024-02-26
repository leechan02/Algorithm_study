#include <iostream>

int arr[1000000];

int recursive(int n) {
  if (n == 1) {
    return 0;
  }
  if (arr[n] != 0) {
    return arr[n];
  }
  arr[n] = recursive(n - 1) + 1;
  if (n % 2 == 0) {
	arr[n] = std::min(arr[n], recursive(n / 2) + 1);
  }
  if (n % 3 == 0) {
	arr[n] = std::min(arr[n], recursive(n / 3) + 1);
  }
  return arr[n];
}

int main() {
  int N;

  std::cin >> N;

  for (int i = 0; i < 1000000; i++) {
	arr[i] = 0;
  }
  std::cout << recursive(N) << std::endl;
  return 0;
}

// 10 5 4 2 1
// 10 9 3 1