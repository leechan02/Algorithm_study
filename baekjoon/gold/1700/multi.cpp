#include <iostream>
#include <vector>
#include <algorithm>

int k, n, arr[104], cnt;
bool visited[104];
std::vector<int> adaptor;

int main() {
  std::cin >> k >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  for (int i = 0; i < n; ++i) {
    if (visited[arr[i]] == false) {
      if (adaptor.size() == k) {
        int last_idx = 0, pos;
        for (int plug : adaptor) {
          int here_pick = 987654321;
          for (int j = i + 1; j < n; ++j) {
            if (plug == arr[j]) {
              here_pick = j;
              break;
            }
          }
          if (last_idx < here_pick) {
            last_idx = here_pick;
            pos = plug;
          }
        }
        ++cnt;
        visited[pos] = false;
        adaptor.erase(std::find(adaptor.begin(), adaptor.end(), pos));
      }
      adaptor.push_back(arr[i]);
      visited[arr[i]] = true;
    }
  }
  std::cout << cnt << "\n";
}