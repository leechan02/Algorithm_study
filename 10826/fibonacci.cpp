#include <iostream>

std::string cache[10000];

std::string operator+(std::string a, std::string b) {
  std::string result;
  int sum;
  int up = 0;

  int i = a.size() - 1;
  int j = b.size() - 1;

  while (i >= 0 || up) {
    sum = up;

    if (i >= 0) {
      sum += a[i] - '0';
      i--;
    }
    if (j >= 0) {
      sum += b[j] - '0';
      j--;
    }

    up = sum / 10;
    result.insert(result.begin(), (sum % 10) + '0');
  }

  return result;
}

std::string recursive(int n) {
  if (n <= 0) {
    return "0";
  } else if (n == 1) {
    return "1";
  }
  if (cache[n] != "") {
    return cache[n];
  }

  return (cache[n] = recursive(n - 1) + recursive(n - 2));
}

int main() {
  int n;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    cache[i] = "";
  }
  std::cout << recursive(n) << std::endl;
}