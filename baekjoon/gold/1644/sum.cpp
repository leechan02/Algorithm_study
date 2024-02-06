#include <iostream>

bool che[4000001];
int a[2000001];
int k, j, hi, ans, sum; 

int main() {
  int n;
  std::cin >> n;
  for (int i = 2; i <= n; ++i) {
    if (che[i]) continue;
    for (int j = 2 * i; j <= n; j += i) {
      che[j] = true;
    }
  }

  for (int i = 2; i <= n; ++i) {
    if (che[i] == false) a[k++] = i;
  }

  while (true) {
    if (sum >= n) sum -= a[j++];
    else if (hi == k) break;
    else sum += a[hi++];
    if (sum == n) ans++;
  }
}