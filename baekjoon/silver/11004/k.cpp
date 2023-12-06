#include <iostream>
#include <vector>

int partition(std::vector<int> &A, int start, int end) {
  if (start + 1 == end) {
    if (A[start] > A[end]) {
      std::swap(A[start], A[end]);
    }
    return end;
  }

  int mid = (start + end) / 2;
  std::swap(A[start], A[mid]);
  int pivot = A[start];
  int left = start + 1, right = end;

  while (left <= right) {
    while (pivot > A[left] && left < A.size() - 1) {
      left++;
    }
    while (pivot < A[right] && right > 0) {
      right--;
    }
    if (left <= right) {
      std::swap(A[left++], A[right--]);
    }
  }

  A[start] = A[right];
  A[right] = pivot;
  return right;
}

void quickSort(std::vector<int> &A, int start, int end, int K) {
  int pivot = partition(A, start, end);
  if (pivot == K) {
    return ;
  } else if (K < pivot) {
    quickSort(A, start, pivot - 1, K);
  } else {
    quickSort(A, pivot + 1, end, K);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, K;
  std::cin >> N >> K;

  std::vector<int> A(N, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  quickSort(A, 0, N - 1, K - 1);
  std::cout << A[K - 1] << '\n';
  return 0;
}
