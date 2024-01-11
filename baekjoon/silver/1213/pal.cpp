#include <iostream>

std::string name;
int alphabet[26];

int main() {
  std::cin >> name;

  for (int i = 0; i < name.size(); ++i) {
    ++alphabet[name[i] - 'A'];
  }

  int odd = -1;
  for (int i = 0; i < 26; ++i) {
    if (alphabet[i] == 0) {
      continue;
    } else if (alphabet[i] % 2 == 1) {
      ++odd;
    }
  }

  if (odd > 0) {
    std::cout << "I'm Sorry Hansoo\n";
  } else {
    for (int i = 0; i < 26; ++i) {
      if (alphabet[i] == 0) {
        continue;
      }
      if (alphabet[i] % 2 == 1) {
        odd = i;
      }
      for (int j = 0; j < alphabet[i] / 2; ++j) {
        std::cout << (char)(i + 'A');
      }
    }
    if (odd >= 0) {
      std::cout << (char)(odd + 'A');
    }
    for (int i = 25; i >= 0; --i) {
      if (alphabet[i] == 0) {
        continue;
      }
      for (int j = 0; j < alphabet[i] / 2; ++j) {
        std::cout << (char)(i + 'A');
      }
    }
  }
}