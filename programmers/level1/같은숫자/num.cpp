#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for (auto n : arr) {
        if (!answer.empty() && answer.back() == n) continue;
        answer.push_back(n);
    }

    return answer;
}