#include <iostream>
#include <vector>
#include <algorithm>

int t;
std::string sound, ans;
std::vector<std::string> animals;

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

void checkFox() {
  std::vector<std::string> sounds = split(sound, " ");
  for (auto s : sounds) {
    auto it = std::find(animals.begin(), animals.end(), s);
    if (it != animals.end()) continue;
    if (ans.size() != 0) ans += " ";
    ans += s;
  }
}

int main() {
  std::cin >> t;
  while (t--) {
    std::getline(std::cin, sound);
    std::string animal;
    while (getline(std::cin, animal)) {
      if (animal == "what does the fox say?") break;
      std::vector<std::string> tmp = split(animal, " ");
      animals.push_back(tmp[tmp.size() - 1]);
    }
    for (auto t : animals) {
      std::cout << t << " ";
    }
    std::cout << "\n";
    checkFox();
    std::cout << ans << "\n";
  }
}