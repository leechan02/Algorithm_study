#include <iostream>
#include <list>

int n, k;
std::list<int> people;
std::list<int> result;

int main() {
  std::cin >> n >> k;

  for (int i = 1; i <= n; ++i) people.push_back(i);

  auto it = people.begin();
  while (n--) {
    for (int i = 1; i < k; ++i) {
      if (it == people.end()) it = people.begin();
      ++it;
    }
    if (it == people.end()) it = people.begin();
    result.push_back(*it);
    it = people.erase(it);
  }

  std::cout << "<";
  for (auto it = result.begin(); it != result.end();) {
    std::cout << *it;
    ++it;
    if (it != result.end()) std::cout << ", ";
  }
  std::cout << ">\n";
}