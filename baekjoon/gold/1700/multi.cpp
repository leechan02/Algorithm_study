#include <iostream>
#include <vector>

#define INF 987654321

int k, n, arr[104], cnt;
bool visited[104];
std::vector<int> v;

int main() {
  std::cin >> k >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  for (int i = 0; i < n; ++i) {
    if (visited[arr[i]] == false) {
      if (v.size() == k) {
        int last_idx = 0, pos;
        for (int idx : v) {
          int here_pick = INF;
          for (int j = i + 1; j < n; ++j) {
            if (idx == arr[j]) {
              here_pick = j;
              break;
            }
          }
          if (last_idx < here_pick) {
            last_idx = here_pick;
            pos = idx;
          }
        }
        visited[pos] = 0;
        ++cnt;
        v.erase(std::find(v.begin(), v.end(), pos));
      }
      v.push_back(arr[i]);
      visited[arr[i]] = true;
    }
  }
  std::cout << cnt << "\n";
}