#include <iostream>
#include <string>

int n, max, sum;
int num[10];
std::string board;

int main() {
  std::cin >> n;
  board = std::to_string(n);

  for (auto i : board) {
    num[i - '0']++;
  }

  for (int i = 0; i < 10; ++i) {
    if (i == 6 || i == 9) continue;
    if (num[max] < num[i]) max = i;
  }

  sum = num[6] + num[9];
  sum += (sum % 2 == 0) ? 0 : 1;
  if (num[max] < sum / 2) std::cout << sum / 2;
  else std::cout << num[max];
}