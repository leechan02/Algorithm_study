#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N, K;
  std::cin >> N >> K;

  std::vector<int> A(N, 0);
  for (auto &i : A) {
    std::cin >> i;
  }

  auto it = std::lower_bound(A.begin(), A.end(), K);
  int index = N - 1;
  if (it != A.end()) {
    index = std::distance(A.begin(), it);
  }

  int cnt = 0, sum = 0;
  for (int i = index; i >= 0; --i) {
    while (sum < K) {
      sum += A[i];
      if (sum > K) {
        sum -= A[i];
        break;
      }
      cnt++;
    }
    if (sum == K) {
      break;
    }
    if (i == 0 && sum + A[i] > K) {
      cnt = 0;
      sum = 0;
      i = index--;
    }
  }
  std::cout << cnt << '\n';
  return (0);
}

// 2 4
// 2
// 3

// 3 9
// 1
// 3
// 5