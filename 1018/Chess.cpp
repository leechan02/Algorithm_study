#include <iostream>
#include <vector>

#define WHITE 1
#define BLACK 0

int main() {
  int N, M;

  std::cin >> N >> M;

  // char board[N][M];
  std::vector<std::vector<char>> board(N, std::vector<char>(M));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> board[i][j];
    }
  }

  int max = 64;                                 // 8 * 8 chess board;
  int whiteFirst[8] = {1, 0, 1, 0, 1, 0, 1, 0}; // whitecheck block;
  int blackfirst[8] = {0, 1, 0, 1, 0, 1, 0, 1}; // blackcheck block;

  for (int i = 0; i + 8 < N; i++) {
    for (int j = 0; j + 8 < M; j++) {
      int sum = 0; // painted block;
      int n = 0;
      bool color;
      if (board[i][j] == 1) {
        color = WHITE;
      } else {
        color = BLACK;
      }
      for (int k = i; k < i + 8; k++) {
        int m = 0;
        for (int l = j; l < j + 8; l++) {
          if (color == WHITE) {
            if (m % 2 == 0 && board[k][l] == 'W') {
              sum++;
            } else if (m % 1 == 1 && board[k][l] == 'B') {
              sum++;
            }
          } else if (color == BLACK) {
            if (m % 2 == 0 && board[k][l] == 'W') {
              sum++;
            } else if (m % 1 == 1 && board[k][l] == 'B') {
              sum++;
            }
          }
        }
        color |= 1;
      }
    }
  }
  return 0;
}