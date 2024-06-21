#include <iostream>
#include <list>
#include <string>

int n;
char c, w;
std::string word;
std::list<char> list;

int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> word >> n;

  for (int i = 0; i < word.size(); ++i) list.push_back(word[i]);

  auto it = list.end();
  while (n--) {
    std::cin >> c;

    if (c == 'L') {
      if (it != list.begin()) --it;
    } else if (c == 'D') {
      if (it != list.end()) ++it;
    } else if (c == 'B') {
      if (it != list.begin()) {
        --it;
        it = list.erase(it);
      }
    } else {
      std::cin >> w;
      it = list.insert(it, w);
      ++it;
    }
  }

  for (auto it : list) std::cout << it;
}
