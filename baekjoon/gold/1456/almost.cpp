#include <iostream>
#include <vector>

int main() {
  long long A, B;
  std::cin >> A >> B;

  long long decimal[10000001];
  for (long long i = 2; i <= 10000000; ++i) {
    decimal[i] = i;
  }

  for (long long i = 2; i * i <= 10000001; ++i) {
    if (decimal[i] == 0) {
      continue;
    }
    for (long long j = i + i; j <= 10000000; j += i) {
      decimal[j] = 0;
    }
  }

  int cnt = 0;
  for (int i = 2; i <= 10000000; ++i) {
    if (decimal[i] != 0) {
      long long temp = decimal[i];
      while ((double)decimal[i] * (double)temp <= (double)B) {
        if ((double)decimal[i] * (double)temp >= (double)A) {
          cnt++;
        }
        temp *= decimal[i];
      }
    }
  }
  std::cout << cnt << '\n';
  return (0);
}