#include <iostream>
#include <limits.h>

int arr[500][500];

int main() {
  int N, M, B;
  std::cin >> N >> M >> B;

  int min = INT_MAX;
  int max = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> arr[i][j];
      min = std::min(min, arr[i][j]);
      max = std::max(max, arr[i][j]);
    }
  }

  int resultTime = INT_MAX;
  int resultHeight = 0;

  for (int h = min; h <= max; h++) {
    int time = 0;
    int inventory = B;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        int diff = arr[i][j] - h;
        if (diff > 0) {
          time += diff * 2;
          inventory += diff;
        } else if (diff < 0) {
          time -= diff;
          inventory += diff;
        }
      }
    }

    if (inventory >= 0 && time <= resultTime) {
      resultTime = time;
      resultHeight = h;
    }
  }

  std::cout << resultTime << " " << resultHeight << std::endl;

  return 0;
}
