#include <iostream>
#include <vector>

std::vector<std::string> split(std::string &str, std::string sep) {
  std::vector<std::string> ret;
  int pos = 0;
  while (pos < str.size()) {
    auto next = str.find(sep, pos);
    if (next == std::string::npos) next = str.size();
    if (next - pos > 0) ret.push_back(str.substr(pos, next - pos));
    pos = next + sep.size();
  }
  return ret;
}

int main() {
  int n;
  std::cin >> n;
  while (n--) {
    std::string str;
    std::string sep;
    std::cin >> str >> sep;
    std::vector<std::string> strings = split(str, sep);
    for (auto s : strings) {
      std::cout << s << "\n";
    }
  }
}