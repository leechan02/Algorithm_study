#include <iostream>

int n, a[1004], cnt[1004], ret = 1, idx;
int prev[1004];

void dfs(int idx) {
  if (idx == -1) return;
  dfs(prev[idx]);
  std::cout << a[idx] << " ";
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::fill(prev, prev + 1004, -1);
  std::fill(cnt, cnt + 1004, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] < a[i] && cnt[i] < cnt[j] + 1) {
        cnt[i] = cnt[j] + 1;
        prev[i] = j;
        if (ret < cnt[i]) {
          ret = cnt[i];
          idx = i;
        }
      }
    }
  }
  std::cout << ret << "\n";
  dfs(idx);
}