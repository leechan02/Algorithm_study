#include <iostream>

bool che[4000001];
int dp[2000001];
int n, k, ans; 

int main() {
  std::cin >> n;
  for (int i = 2; i <= n; ++i) {
    if (che[i]) continue;
    for (int j = 2 * i; j <= n; j += i) {
      che[j] = true;
    }
  }

  for (int i = 2; i <= n; ++i) {
    if (che[i] == false) dp[k++] = i;
  }

  int from = 0, to = 0, sum = 0;
  while (true) {
    if (sum >= n) sum -= dp[from++];
    else if (to == k) break;
    else sum += dp[to++];
    if (sum == n) ans++;
  }
  std::cout << ans << "\n";
}