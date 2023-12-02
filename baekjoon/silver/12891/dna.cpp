#include <iostream>
#include <vector>

int charToIndex(char ch) {
  switch (ch)
  {
    case 'A': return 0;
    case 'C': return 1;
    case 'G': return 2;
    case 'T': return 3;
    default: return -1;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int S, P;
  std::cin >> S >> P;

  std::string dna;
  std::cin >> dna;

  std::vector<int> count(4), required(4);
  for (int i = 0; i < 4; ++i) {
    std::cin >> required[i];
  }

  for (int i = 0; i < P; ++i) {
    count[charToIndex(dna[i])]++;
  }

  int start = 0, valid = 0;
  while (start + P <= S) {
    bool isValid = true;
    for (int i = 0; i < 4; ++i) {
      if (count[i] < required[i]) {
        isValid = false;
        break;
      }
    }
    valid += isValid;

    if (start + P < S) {
      count[charToIndex(dna[start])]--;
      count[charToIndex(dna[start + P])]++;
    }
    start++;
  }
  std::cout << valid << '\n';
  return (0);
}