#include <iostream>

int ret;
int alphabet[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int num[4004];
std::string a, b, s, ans;

int main() {
  std::cin >> a >> b;

  for (int i = 0; i < a.size(); ++i) {
    s += a[i];
    s += b[i];
  }

  for (int i = 0; i < s.size(); ++i) {
    num[i] = alphabet[s[i] - 'A'];
  }

  for (int i = 1; i < s.size() - 1; ++i) {
    for (int j = 0; j < s.size() - i; ++j) {
      num[j] = (num[j] + num[j + 1]) % 10;
    }
  }
  ans = std::to_string(num[0]) + std::to_string(num[1]);
  std::cout << ans << "\n";
}