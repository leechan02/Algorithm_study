#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, M;
  std::cin >> N;

  std::vector<int> A(N, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }
  std::sort(A.begin(), A.end());

  std::cin >> M;

  std::vector<int> arr(M, 0);
  for (int i = 0; i < M; ++i) {
    std::cin >> arr[i];
  }

  std::vector<int>::iterator it = A.begin();
  for (int i = 0; i < arr.size(); ++i) {
    it = std::lower_bound(A.begin(), A.end(), arr[i]);
    if (it != A.end() && *it == arr[i]) {
      std::cout << "1" << '\n';
    } else {
      std::cout << "0" << '\n';
    }
  }
  return (0);
}