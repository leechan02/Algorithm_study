#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N;
  std::cin >> N;
  std::vector<std::pair<int, int>> A(N);

  for (int i = 0; i < N; ++i) {
	std::cin >> A[i].first;
	A[i].second = i;
  }

  std::sort(A.begin(), A.end());
  int max = 0;

  for (int i = 0; i < N; ++i) {
	if (max < A[i].second - i) {
		max = A[i].second - i;
	}
  }
  std::cout << max  + 1 << '\n';
  return (0);
}