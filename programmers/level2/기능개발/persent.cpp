#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> pro, vector<int> speeds) {
    vector<int> answer;
    while (!pro.empty()) {
        for (int i = 0; i < pro.size(); ++i) {
            pro[i] += speeds[i];
        }
        int tmp = 0;
        while (!pro.empty() && pro[0] >= 100) {
            pro.erase(pro.begin());
            speeds.erase(speeds.begin());
            ++tmp;
        }
        if (tmp) answer.push_back(tmp);
    }
    return answer;
}