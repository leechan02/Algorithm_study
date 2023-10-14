#include "limits.h"
#include <iostream>
#include <vector>

int W[11][11];        // city board
int result = INT_MAX; // total result;

void getPath(std::vector<int> &path, std::vector<bool> &visit, int &N, int sum,
             int from) {
  if (path.size() == N) {
    sum += W[from][path[0]]; // sum last city to first city;
    if (sum < result) {
      result = sum; // change the shortest path;
    }
    return;
  }
  for (int i = 1; i <= N; i++) {
    if (visit[i] == true || i == from) {
      continue;
    } else {
      visit[i] = true;   // check visit flag;
      path.push_back(i); // push the number of the cisy list;
      if (from == 0) {
        getPath(path, visit, N, sum, i); // first recursive;
      } else {
        getPath(path, visit, N, sum + W[from][i], i);
      }
      path.pop_back();  // reset the number of city;
      visit[i] = false; // reset the visit flag;
    }
  }
}

int main() {
  int N;
  std::cin >> N;

  // fill city board;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cin >> W[i][j];
    }
  }

  // fill visit flag;
  std::vector<bool> visit;
  for (int i = 0; i <= N; i++) {
    visit.push_back(false);
  }

  std::vector<int> path; // number of the city list;
  getPath(path, visit, N, 0, 0);

  std::cout << result;
  return 0;
}