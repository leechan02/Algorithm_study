#include <iostream>
#include <vector>

int main() {
  long long min, max;
  std::cin >> min >> max;

  std::vector<bool> decimal(max - min + 1);

  for (long long i = 2; i * i <= max; ++i) {
    long long power = i * i;
    long long start = min / power;

    if (min % power != 0) {
      start++;
    }
    for (long long j = start; power * j <= max; ++j) {
      decimal[(int)((j * power) - min)] = true;
    }
  }

  long long cnt = 0;
  for (long long i = 0; i <= max - min; ++i) {
    if (!decimal[i]) {
      ++cnt;
    }
  }
  std::cout << cnt << "\n";
  return (0);
}