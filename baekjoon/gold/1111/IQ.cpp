#include <iostream>
#include <cmath>

int main() {
  int N;
  int result;

  std::cin >> N;

  int arr[N];
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  if (N == 1) {
    std::cout << 'A';
  } else if (N == 2) {
    if (arr[0] == arr[1]) {
      std::cout << arr[1];
    } else {
      std::cout << 'A';
    }
  } else {
    int a = 0;
    if (arr[1] - arr[0] != 0) {
      a = ((arr[1] - arr[2]) / (arr[0] - arr[1]));
    }
    
    int b = arr[1] - arr[0] * a;
    for (int i = 0; i < N - 1; i++) {
      if (arr[i + 1] != arr[i] * a + b) {
        std::cout << 'B';
        return 0;
      }
    }
    std::cout << arr[N - 1] * a + b;
  }
  return 0;
}