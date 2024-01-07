#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;

    int dp[1001][1001];

    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }

    std::cout << dp[N][K] << "\n";
    return 0;
}
