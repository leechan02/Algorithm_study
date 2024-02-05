#include <iostream>
#include <algorithm>

#define row 1
#define col 0

int n;
int ans = 987654321;
bool coins[21][21];

int check() {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (coins[i][j] == true) {
        ++cnt;
      }
    }
  }
  return cnt;
}

void change(bool which, int idx) {
  if (which == row) {
    for (int i = 0; i < n; ++i) {
      coins[idx][i] = !coins[idx][i];
    }
  } else {
    for (int i = 0; i < n; ++i) {
      coins[i][idx] = !coins[i][idx];
    }
  }
}

void dfs(bool which, int idx, int rc, int cc) {
  if (rc > n + 1 || cc > n + 1) return;
  if (rc == n + 1 && cc == n + 1) {
    ans = std::min(ans, check());
    return;
  }
  if (which == row) change(row, idx);
  else change(col, idx);
  dfs(row, idx + 1, rc + 1, cc);
  change(row, idx);
  dfs(col, idx + 1, rc, cc + 1);
  change(col, idx);
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string tmp;
    std::cin >> tmp;
    for (int j = 0; j < n; ++j) {
      if (tmp[j] == 'T') {
        coins[i][j] = true;
      }
    }
  }
  dfs(row, 0, 0, 0);
  std::cout << ans << "\n";
}