#include <iostream>
#include <vector>
#include <algorithm>

bool binarySearch(int num, std::vector<int> &A) {
  int start = 0, end = A.size() - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (num > A[mid]) {
      start = mid + 1;
    } else if (num < A[mid]) {
      end = mid - 1;
    } else {
      return true;
    }
  }
  return false;
}


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

  for (int i = 0; i < arr.size(); ++i) {
    if (binarySearch(arr[i], A)) {
      std::cout << "1" << '\n';
    } else {
      std::cout << "0" << '\n';
    }
  }
  return (0);
}