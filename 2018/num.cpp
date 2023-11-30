#include <iostream>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N;
  std::cin >> N;
  int count = 1;
  int start_index = 1;
  int end_index = 1;
  int sum = 1;

  while (end_index != N) {
    if (sum == N) {
      count++;
      end_index++;
      sum += end_index;
    } else if (sum > N) {
      sum -= start_index;
      start_index++;
    } else {
      end_index++;
      sum += end_index;
    }
  }

  std::cout << count << '\n';
  return (0);
}
