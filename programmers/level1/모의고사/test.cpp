#include <string>
#include <vector>

using namespace std;

vector<int> ans;
vector<int> first = {1, 2, 3, 4, 5};
vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int f, s, t;

void com() {
	if (f >= s && f >= t) {
        ans.push_back(1);
    }
	if (s >= f && s >= t) {
        ans.push_back(2);
    }
	if (t >= f && t >= s) {
        ans.push_back(3);
    }
}

vector<int> solution(vector<int> answers) {
    
    for (int i = 0; i < answers.size(); ++i) {
        if (answers[i] == first[i % 5]) ++f;
        if (answers[i] == second[i % 8]) ++s;
        if (answers[i] == third[i % 10]) ++t;
    }
    
    com();
    
    return ans;
}