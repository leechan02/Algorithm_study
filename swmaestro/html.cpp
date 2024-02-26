#include <iostream>
#include <vector>
#include <map>

std::map<std::string, std::vector<int>> m;

void init(std::string &text) {
  std::string id(1, text[0]);
  if (text.size() == 1) {
    m[id].push_back(16);
    return;
  }
  int pos = 2;
  while (pos < text.size()) {
    auto next = text.find(" ", pos);
    if (next == std::string::npos) next = text.size();
    if (next - pos > 0) m[id].push_back(std::stoi(text.substr(pos, next - pos)));
    pos = next + 1;
  }
  m[id].push_back(16);
}

int main() {
  std::vector<std::string> text = {"f 1 2 3", "g 5 2 99", "d"};

  for (auto t : text) {
    init(t);
  }

  auto v = m["d"];
  for (auto t : v) {
    std::cout << t << " ";
  }
}