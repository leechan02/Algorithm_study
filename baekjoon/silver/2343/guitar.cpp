#include <iostream>
#include <vector>

int main() {
  int N, M, start = 0, end = 0;
  std::cin >> N >> M;

  std::vector<int> arr(N, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> arr[i];
    if (start < arr[i]) {
      start = arr[i];
    }
    end += arr[i];
  }

  while (start <= end) {
    int mid = (start + end) / 2;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < N; ++i) {
      if (sum + arr[i] > mid) {
        count++;
        sum = 0;
      }
      sum += arr[i];
    }
    if (sum != 0) {
      count++;
    }
    if (count > M) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  std::cout << start << '\n';

  return (0);
}