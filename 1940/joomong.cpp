#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, M;
  std::cin >> N >> M;

  std::vector<int> arr(N, 0);

  for (int i = 0; i < N; ++i) {
    std::cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  int start = 0, end = N - 1, count = 0, sum;
  while (start < end) {
    sum = arr[start] + arr[end];
    if (sum == M) {
      count++;
      start++;
      end--;
    } else if (sum < M) {
      start++;
    } else {
      end--;
    }
  }
  std::cout << count << '\n';
  return (0);
}