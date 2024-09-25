#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<int, int> map;

long long solution(vector<int> a, vector<int> b) {
    int n = a.size();
    long long count = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) ++count;

        int sum = a[i] + b[i];
        count += map[sum];
        map[sum]++;
    }

    return count;
}

int main() {
    vector<int> a = {1, -1, 4, 5};
    vector<int> b = {5, 3, 4, 1};

    cout << solution(a, b) << "\n";

    return 0;
}