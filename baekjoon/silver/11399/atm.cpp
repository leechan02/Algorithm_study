#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int P[N];
  for (int i = 0; i < N; ++i) {
    std::cin >> P[i];
  }

  int index, tmp;
  for (int i = 0; i < N; ++i) {
    index = i;
    for (int j = 0; j < i; ++j) {
      if (P[i] < P[j]) {
        index = j;
        break;
      }
    }
    tmp = P[i];
    for (int k = i; k > index; --k) {
      P[k] = P[k - 1];
    }
    P[index] = tmp;
  }

  int result = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= i; ++j) {
      result += P[j];
    }
  }
  std::cout << result << '\n';
  return (0);
}