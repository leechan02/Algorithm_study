#include <iostream>

struct Team {
  int score = 0;
  int time = 0;
  int start = 0;
  bool flag = false;
};

int main() {
  int n;
  std::cin >> n;

  Team one;
  Team two;
  int team, time, mm, ss;
  while (n--) {
    std::string tmp;
    std::cin >> team >> tmp;

    mm = atoi(tmp.substr(0, 2).c_str());
    ss = atoi(tmp.substr(3).c_str());
    time = mm * 60 + ss;
    if (team == 1) {
      ++one.score;
    } else {
      ++two.score;
    }

    if (one.score > two.score && one.flag == false) {
      one.start = time; one.flag = true;
    } else if (one.score < two.score && two.flag == false) {
      two.start = time; two.flag = true;
    } else if (one.score == two.score) {
      if (one.flag == true) {
        one.time += time - one.start;
        one.start = 0; one.flag = false;
      }
      if (two.flag == true) {
        two.time += time - two.start;
        two.start = 0; two.flag = false;
      }
    }
  }
  if (one.score > two.score) {
    one.time += 48 * 60 - one.start;
  }
  if (two.score > one.score) {
    two.time += 48 * 60 - two.start;
  }

  std::cout << ((one.time / 60 < 10) ? "0" : "") << one.time / 60 << ":"
            << ((one.time % 60 < 10) ? "0" : "") << one.time % 60 << "\n";
  std::cout << ((two.time / 60 < 10) ? "0" : "") << two.time / 60 << ":"
            << ((two.time % 60 < 10) ? "0" : "") << two.time % 60 << "\n";
}