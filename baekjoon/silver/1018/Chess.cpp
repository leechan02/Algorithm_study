#include <iostream>
#include <vector>

#define WHITE 1
#define BLACK 0

int main() {
  int N, M;

  std::cin >> N >> M;

  // char board[N][M];
  std::vector<std::vector<char> > board(N, std::vector<char>(M));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> board[i][j];
    }
  }

  int max = 64; // 8 * 8 chess board;
  char whiteFirst[8] = {'W', 'B', 'W', 'B',
                        'W', 'B', 'W', 'B'}; // whitecheck block;
  char blackfirst[8] = {'B', 'W', 'B', 'W',
                        'B', 'W', 'B', 'W'}; // blackcheck block;

  for (int i = 0; i + 8 <= N; i++) {
    for (int j = 0; j + 8 <= M; j++) {
      bool color = WHITE;
      for (int c = 0; c < 2; c++) {
        int sum = 0; // painted block;
        for (int k = i, n = 0; k < i + 8; k++, n++) {
          for (int l = j, m = 0; l < j + 8; l++, m++) {
            if (color == WHITE) {
              if (board[k][l] != whiteFirst[m]) {
                sum++;
              }
            } else if (color == BLACK) {
              if (board[k][l] != blackfirst[m]) {
                sum++;
              }
            }
          }
          color ^= 1;
        }
        if (sum < max) {
          max = sum;
        }
        color = BLACK;
      }
    }
  }
  std::cout << max;
  return 0;
}