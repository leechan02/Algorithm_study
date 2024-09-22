#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::string ans;
std::vector<std::string> stringNumbers;

bool cmp(std::string a, std::string b) {
    return a + b > b + a;
}

std::string solution(std::vector<int> numbers) {
    for (auto &num : numbers) {
        stringNumbers.push_back(std::to_string(num));
    }
    
    std::sort(stringNumbers.begin(), stringNumbers.end(), cmp);
    
    for (auto &num : stringNumbers) {
        ans += num;
    }
    
    ans[0] == '0' ? ans = "0" : ans;
    
    return ans;
}