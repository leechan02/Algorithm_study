#include <iostream>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int S, P;
  std::cin >> S >> P;

  std::string dna;
  std::cin >> dna;

  int A, C, G, T;
  std::cin >> A >> C >> G >> T;

  int start = 0, end = P - 1, count = 0;
  while (end < S) {
    int a = 0, c = 0, g = 0, t = 0;
    for (int i = start; i < start + P; ++i) {
      if (dna[i] == 'A') {
        a++;
      } else if (dna[i] == 'C') {
        c++;
      } else if (dna[i] == 'G') {
        g++;
      } else if (dna[i] == 'T') {
        t++;
      }
    }
    if (a >= A && c >= C && g >= G && t >= T) {
      count++;
    }
    start++, end++;
  }
  std::cout << count << '\n';
  return (0);
}