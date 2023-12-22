#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int t;
  std::cin >> t;
  
  std::vector<long long> ans(t, 0);
  for (int k = 0; k < t; ++k) {
    int n;
    std::cin >> n;
    std::vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
      std::cin >> arr[i];
    }
    long long res = 0;
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        res += std::gcd(arr[i], arr[j]);
      }
    }
    ans[k] = res;
  }

  for (auto i : ans) {
    std::cout << i << '\n';
  }
  return (0);
}