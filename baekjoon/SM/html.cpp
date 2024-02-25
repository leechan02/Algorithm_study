#include <iostream>
#include <vector>
#include <map>

std::map<std::string, std::vector<int>> m;

void init(std::string &text) {
  if (text.size() == 1) {
    m[std::to_string(text[0])].push_back(16);
  }
}

int main() {
  std::vector<std::string> text = {"f 1 2 3", "g 5 2 99", "d"};

  for (auto t : text) {
    init(t);
  }
}