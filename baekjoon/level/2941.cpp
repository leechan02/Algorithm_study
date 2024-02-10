#include <iostream>
#include <string>
#include <vector>

int index;
std::string input;
std::vector<std::string> croatia = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=",  "z="};

int main() {
  std::cin >> input;

  for (int i = 0; i < croatia.size(); i++) {
    while (true) {
      index = input.find(croatia[i]);
      if (index == std::string::npos)
        break;
      input.replace(index, croatia[i].size(), "1");
    }
  }

  std::cout << input.length();
}