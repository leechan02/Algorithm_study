#include <iostream>

int main() {
  std::string N;
  std::cin >> N;

  int max;
  for (int i = 0; i < N.size() - 1; ++i) {
    max = i;
    for (int j = i; j < N.size(); ++j) {
      if (N[max] < N[j]) {
        max = j;
      }
    }
    std::swap(N[i], N[max]);
  }
  std::cout << N << '\n';
  return (0);
}