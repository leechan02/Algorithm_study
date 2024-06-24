#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

int t, n;

int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> t;

  while (t--) {
    std::string p, arr;
    std::cin >> p >> n >> arr;

    std::deque<int> dq;
    std::string tmp;
    for (int i = 1; i < arr.size(); ++i) {
      if (std::isdigit(arr[i])) {
        tmp += arr[i];
      } else if (arr.size() > 2) {
        dq.push_back(std::atoi(tmp.c_str()));
        tmp.clear();
      }
    }

    bool err = false;
    bool reverse = false;
    for (int i = 0; i < p.size(); ++i) {
      if (p[i] == 'R') {
        reverse = !reverse;
      } else {
        if (dq.empty()) {
          err = true;
          break;
        } else {
          if (reverse) dq.pop_back();
          else dq.pop_front();
        }
      }
    }

    if (err) {
      std::cout << "error\n";
    } else {
      std::cout << "[";
      if (reverse) std::reverse(dq.begin(), dq.end());
      for (auto it = dq.begin(); it != dq.end();) {
        std::cout << *it;
        if (++it != dq.end()) {
          std::cout << ",";
        }
      }
      std::cout << "]\n";
    }
  }
}