#include <iostream>

std::string sum(std::string a, std::string b) {
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
  std::string arr[n + 1];

  arr[0] = "0";
  arr[1] = "1";
  for (int i = 2; i <= n; i++) {
    arr[i] = sum(arr[i - 1], arr[i - 2]);
  }
  return (arr[n]);
}

int main() {
  int n;

  std::cin >> n;
  std::cout << recursive(n) << std::endl;
}