#include <iostream>

#define BLUE 1
#define WHITE 0

int white = 0;
int blue = 0;
bool color = WHITE;

bool arr[128][128];

void recursive(int i, int j, int end) {
  if (end == 0) {
    return;
  }
  int check = 0;
  color = arr[i][j];
  for (int k = i; k < i + end; k++) {
    for (int l = j; l < j + end; l++) {
      if (arr[k][l] != color) {
        check = 1;
        break;
      }
    }
    if (check == 1) {
      break;
    }
  }
  if (check == 1) {
    recursive(i, j, end / 2);                     // 1 sqaure
    recursive(i + end / 2, j, end / 2);           // 2 sqaure
    recursive(i, j + end / 2, end / 2);           // 3 sqaure
    recursive(i + end / 2, j + end / 2, end / 2); // 4 sqaure
  } else {
    if (color == WHITE) {
      white++;
    } else {
      blue++;
    }
  }
}

int main() {
  int N;
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> arr[i][j];
    }
  }

  recursive(0, 0, N);
  std::cout << white << std::endl;
  std::cout << blue << std::endl;
  return 0;
}