#include <iostream>

int main() {
  int N;

  std::cin >> N;

  int sum = INT_MAX;
  int i = 0;
  int three = 0;
  while (i <= N) {
    int j = i;
    int five = 0;
    while (j <= N) {
      if (j == N && three + five < sum) {
        sum = three + five;
      }
      j += 5;
      five++;
    }
    i += 3;
    three++;
  }
  if (sum == INT_MAX) {
    std::cout << "-1" << std::endl;
    return (0);
  }

  std::cout << sum << std::endl;
  return (0);
}