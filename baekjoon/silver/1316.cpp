#include <iostream>
#include <cstring>

int n, cnt;
std::string str;
bool visited[26];

bool checkStr() {
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < str.size(); ++i) {
    if (visited[str[i] - 'a'] == false) visited[str[i] - 'a'] = true;
    else if (str[i] == str[i - 1]) continue;
    else return false;
  }
  return true;
}

int main() {
  std::cin >> n;
  while (n--) {
    std::cin >> str;
    if (checkStr()) ++cnt;
  }
  std::cout << cnt << "\n";
}