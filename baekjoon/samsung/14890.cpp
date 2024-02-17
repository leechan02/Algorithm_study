#include <iostream>
#include <vector>
#include <cstring>

int n, l, cnt;
int map[201][201];
bool visited[201];
std::vector<int> list[201];

int checkHigh(int i) {
  for (int j = 1; j < n; ++j) {
    if (abs(list[i][j - 1] - list[i][j]) > 1) return 1;
  }
  return 0;
}

int putSlide(int i) {
  memset(visited, 0, sizeof(visited));
  for (int j = 0; j < n - 1;) {
    if (list[i][j] > list[i][j + 1]) {
      int put = j + 1;
      for (int k = 0; k < l; ++k) {
        if (put >= n || visited[put] == true || list[i][j + 1] != list[i][put]) return 1;
        visited[put] = true;
        ++put;
      }
      j += l;
    } else if (list[i][j] < list[i][j + 1]) {
      int put = j;
      for (int k = 0; k < l; ++k) {
        if (put < 0 || visited[put] == true || list[i][j] != list[i][put]) return 1;
        visited[put] = true;
        --put;
      }
      ++j;
    } else ++j;
  }
  return 0;
}

int main() {
  std::cin >> n >> l;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      list[i].push_back(map[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      list[i + n].push_back(map[j][i]);
    }
  }

  for (int i = 0; i < 2 * n; ++i) {
    if (checkHigh(i) || putSlide(i)) continue;
    ++cnt;
  }
  std::cout << cnt << "\n";
  return 0;
}