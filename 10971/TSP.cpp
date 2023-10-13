#include "limits.h"
#include <iostream>
#include <vector>

int W[11][11];
int path;

void getPath(std::vector<bool> &visit, int &N, int sum, int from) {
  if (from == N) {
    if (sum < path)
      path = sum;
    return;
  }
  for (int i = 1; i <= N; i++) {
    if (from == 0) {
      visit[i] = true;
      getPath(visit, N, sum, i);
    } else if (visit[i] == true || i == from) {
      continue;
    } else {
      visit[i] = true;
      getPath(visit, N, sum + W[from][i], i);
      visit[i] = false;
    }
  }
}

int main() {
  int N;
  std::cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cin >> W[i][j];
    }
  }

  std::vector<bool> visit;
  for (int i = 0; i <= N; i++) {
    visit.push_back(false);
  }

  path = INT_MAX;
  getPath(visit, N, 0, 0);

  // for (int i = 1; i <= 4; i++) {
  //   int sum = 0;
  //   visit[i] = true;
  //   for (int j = 1; j <= 4; j++) {
  //     if (visit[j] == true || i == j)
  //       continue;
  //     else {
  //       visit[j] = true;
  //       sum += W[i][j];
  //     }
  //     for (int k = 1; k <= 4; k++) {
  //       if (visit[k] == true || j == k)
  //         continue;
  //       else {
  //         visit[k] = true;
  //         sum += W[j][k];
  //       }
  //       for (int l = 1; l <= 4; l++) {
  //         if (visit[l] == true || k == l)
  //           continue;
  //         else {
  //           visit[l] = true;
  //           sum += W[k][l];
  //           sum += W[l][i];
  //           if (sum < path)
  //             path = sum;
  //           visit[l] = false;
  //         }
  //       }
  //       visit[k] = false;
  //     }
  //     visit[j] = false;
  //   }
  //   visit[i] = false;
  // }
  std::cout << path;
  return 0;
}