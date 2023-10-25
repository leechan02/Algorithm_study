#include <iostream>

int arr[15][15];

int main() {
  int T, k, n;

  for (int j = 1; j < 15; j++) {
    arr[0][j] = j;
  }
  for (k = 1; k < 15; k++) {
    for (n = 1; n < 15; n++) {
      int tmp = 0;
      for (int i = 1; i <= n; i++) {
        tmp += arr[k - 1][i];
      }
      arr[k][n] = tmp;
    }
  }

  std::cin >> T;
  for (int i = 0; i < T; i++) {
    std::cin >> k >> n;
    std::cout << arr[k][n] << std::endl;
  }
  return 0;
}

// k floor n room
// 1 3
// 0 : 1 2 3
// 1 : 1 3 6
// 2 : 1 4 10
// 3 : 1 5 15
// 4 : 1 6 16