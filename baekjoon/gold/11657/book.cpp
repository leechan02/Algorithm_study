#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

typedef std::tuple<int, int, int> edge;
int n, m;
std::vector<long long> mdistance;
std::vector<edge> edges;

int main() {
  std::cin >> n >> m;
  mdistance.resize(n + 1);
  std::fill(mdistance.begin(), mdistance.end(), LONG_MAX);

  for (int i = 0; i < m; ++i) {
    int start, end, time;
    std::cin >> start >> end >> time;
    edges.push_back(std::make_tuple(start, end, time));
  }

  mdistance[1] = 0;

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      edge medge = edges[j];
      int start = std::get<0>(medge);
      int end = std::get<1>(medge);
      int time = std::get<2>(medge);

      if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time) {
        mdistance[end] = mdistance[start] + time;
      }
    }
  }
  bool mCycle = false;

  for (int i = 0; i < m; ++i) {
    edge medge = edges[i];
    int start = std::get<0>(medge);
    int end = std::get<1>(medge);
    int time = std::get<2>(medge);

    if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time) {
      mCycle = true;
    }
  }

  if (!mCycle) {
    for (int i = 2; i <= n; ++i) {
      if (mdistance[i] == LONG_MAX) {
        std::cout << "-1\n";
      } else {
        std::cout << mdistance[i] << "\n";
      }
    }
  } else {
    std::cout << "-1\n";
  }
  return (0);
}