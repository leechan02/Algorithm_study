#include <iostream>
#include <stack>

int n, cnt;
std::string str;

void remove(std::string &str) {
  std::stack<char> st;
  for (char c : str) {
    if (!st.empty() && st.top() == c) {
      st.pop();
    } else {
      st.push(c);
    }
  }
  str = "";
  while (!st.empty()) {
    str = st.top() + str;
    st.pop();
  }
}

int main() {
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    std::cin >> str;
    if (str.size() & 1) {
      continue;
    }
    remove(str);
    if (str == "") {
      ++cnt;
    }
  }
  std::cout << cnt << '\n';
  return 0;
}