#include <iostream>

long long n;
long long arr[100001];
bool visited[100001];

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  long long ans = 0, from = 0, to = 0;
  while (from < n) {
    if (visited[arr[to]] == false) {
      visited[arr[to]] = true;
      if (to < n) {
        ++to;
      }
    } else {
      ans += (to - from);
      visited[arr[from]] = false;
      ++from;
    }
  }
  ans += (to - from);
  std::cout << ans << "\n";
}