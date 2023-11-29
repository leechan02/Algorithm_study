#include <iostream>

int main() {
  int N, M, i, j;

  scanf("%d %d", &N, &M);

  int arr[N + 1];
  for (int i = 1; i <= N; ++i) {
	scanf("%d", &arr[i]);
  }

  int S[N + 1];
  S[0] = 0;
  for (int i = 1; i <= N; ++i) {
    S[i] = S[i - 1] + arr[i];
  }

  for (int k = 1; k <= M; ++k) {
	scanf("%d %d", &i, &j);
	printf("%d\n", S[j] - S[i - 1]);
  }
  return (0);
}