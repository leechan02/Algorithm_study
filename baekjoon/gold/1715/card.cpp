#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N, ans = 0;
  std::cin >> N;

  std::vector<int> arr(N, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> arr[i];
  }

  std::sort(arr.begin(), arr.end());
  for (int i = 0; i < N - 1; ++i) {
    int tmp = arr[0] + arr[1];
    arr.erase(arr.begin(), arr.begin() + 2);
    std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), tmp);
    arr.insert(it, tmp);
    ans += tmp;
  }
  std::cout << ans << '\n';
  return (0);
}
