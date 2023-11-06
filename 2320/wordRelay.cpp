#include <iostream>

std::string arr[16];
int dp[16] = {
    0,
};

int recursive(int n) {
  if (n == 0) {
    return arr[0].size();
  }
  if (dp[n] != 0) {
    return dp[n];
  }
  for (int i = 0; i < n; i++) {
    if (arr[n].back() == arr[i].front()) {
      dp[n] = arr[n].size() + arr[i].size();
      recursive(n - 1);
    }
  }
  return dp[n]; 
}

int main() {
  int N;

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  std::cout << recursive(N);
}