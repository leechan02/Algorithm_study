#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  vector<int> numbers;
  stringstream ss(s);
  string tmp;

  while (ss >> tmp) {
    numbers.push_back(stoi(tmp));
  }

  sort(numbers.begin(), numbers.end());

  return to_string(numbers[0]) + " " + to_string(numbers[numbers.size() - 1]);
}