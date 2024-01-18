#include <iostream>
#include <cstring>

int cloud[104][104];

int main() {
  int h, w;
  std::cin >> h >> w;

  memset(cloud, -1, sizeof(cloud));
  for (int i = 0; i < h; ++i) {
    std::string tmp;
    std::cin >> tmp;
    for (int j = 0; j < w; ++j) {
      if (tmp[j] == 'c') {
        cloud[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (cloud[i][j] == 0) {
        ++j;
        while (j < w && cloud[i][j] == -1) {
          cloud[i][j] = cloud[i][j - 1] + 1;
          ++j;
        }
        --j;
      }
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cout << cloud[i][j] << " ";
    }
    std::cout << "\n";
  }
}