#include <cctype>
#include <iostream>

std::string str;
int alphabet[26], max, cnt, idx;

int main() {
  std::cin >> str;

  for (int i = 0; i < str.size(); ++i) {
    str[i] = std::toupper(str[i]);
    alphabet[str[i] - 'A']++;
  }

  for (int i = 0; i < 26; ++i) {
    if (max < alphabet[i]) {
      max = alphabet[i];
      idx = i;
      cnt = 1;
    } else if (max == alphabet[i]) {
      cnt++;
    }
  }

  std::cout << (cnt > 1 ? '?' : static_cast<char>(idx + 'A')) << "\n";
}
