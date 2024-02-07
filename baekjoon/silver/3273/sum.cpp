#include <iostream>
#include <vector>
#include <algorithm>

int n, x;

int main() {
  std::cin >> n;
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  std::cin >> x;

  std::sort(arr.begin(), arr.end());

  int from = 0, to = n - 1, ans = 0;
  while (from < to) {
    int tmp = arr[from] + arr[to];
    if (tmp == x) ++ans;
    if (tmp >= x) --to;
    else if (tmp < x) ++from;
  }
  std::cout << ans << "\n";
}