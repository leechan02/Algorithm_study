#include <iostream>
#include <stack>
#include <string>

int bar, light, res;
int stick[100000], laser[100000];
std::stack<int> s;
std::string a;

int main() {
  std::cin >> a;

  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == '(') {
      s.push(i);
    } else {
      if (!s.empty()) {
        bar = i - s.top();
        if (bar != 1) {
          stick[s.top()] = bar;
        } else {
          ++light;
        }
        s.pop();
      }
    }
    laser[i] = light;
  }

  for (int i = 0; i < a.size(); ++i) {
    if (stick[i] != 0) {
      int point = laser[i + stick[i]] - laser[i];
      res += point + 1;
    }
  }
  std::cout << res << "\n";
}