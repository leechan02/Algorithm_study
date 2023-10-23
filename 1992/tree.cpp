#include <iostream>

#define BLUE '1'
#define WHITE '0'

char color = WHITE;
char arr[128][128];

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
    std::cout << "(";
    recursive(i, j, end / 2);                     // 1 sqaure
    recursive(i, j + end / 2, end / 2);           // 3 sqaure
    recursive(i + end / 2, j, end / 2);           // 2 sqaure
    recursive(i + end / 2, j + end / 2, end / 2); // 4 sqaure
    std::cout << ")";
  } else {
    if (color == WHITE) {
      std::cout << "0";
    } else {
      std::cout << "1";
    }
  }
}

int main() {
  int N;
  std::string tmp;
  std::cin >> N;

  for (int i = 0; i < N; i++) {
      std::cin >> arr[i];
  }

  recursive(0, 0, N);
  return 0;
}