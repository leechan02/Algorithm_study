#include <iostream>
#include <vector>

std::vector<int> arr;
std::vector<int> sorted;
long long result = 0;

void merge(int left, int right) {
  int mid = (left + right) / 2;
  int i = left;
  int j = mid + 1;
  int k = left;

  while (i <= mid && j <= right) {
    if (arr[i] > arr[j]) {
      sorted[k++] = arr[j++];
      result += j - k;
    } else {
      sorted[k++] = arr[i++];
    }
  }

  if (i > mid) {
    while (j <= right) {
      sorted[k++] = arr[j++];
    }
  } else {
    while (i <= mid) {
      sorted[k++] = arr[i++];
    }
  }

  for (int a = left; a <= right; a++) {
    arr[a] = sorted[a];
  }
}

void mergeSort(int left, int right) {
  int mid;

  if (left < right) {
    mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, right);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N;
  std::cin >> N;

  arr = std::vector<int>(N, 0);
  sorted = std::vector<int>(N, 0);

  for (int i = 0; i < N; ++i) {
    std::cin >> arr[i];
  }

  mergeSort(0, N - 1);

  std::cout << result << "\n";
  return (0);
}