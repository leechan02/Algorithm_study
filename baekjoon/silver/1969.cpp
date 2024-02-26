#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

int n, m, min = 1e9, sum, max;
std::string str, ret;
char dna[1004][54];
int num[26];

char checkMax(int j) {
  memset(num, 0, sizeof(num));
  for (int i = 0; i < n; ++i) {
    num[dna[i][j] - 'A']++;
  }
  int max = 0, idx;
  for (int i = 0; i < 26; ++i) {
    if (max < num[i]) {
      max = num[i];
      idx = i;
    }
  }
  return idx + 'A';
}

int checkNum(char ch, int j) {
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    if (dna[i][j] != ch) ++ret;
  }
  return ret;
}

int main () {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::cin >> str;
    for (int j = 0; j < m; ++j) {
      dna[i][j] = str[j];
    }
  }

  char ch;
  for (int j = 0; j < m; ++j) {
    ch = checkMax(j);
    sum += checkNum(ch, j);
    ret += ch;
  }
  std::cout << ret << "\n" << sum << "\n";
}