#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> people;

string solution(vector<string> part, vector<string> com) {
    for (auto p : part) {
        people[p]++;
    }
    for (auto c: com) {
        people[c]--;
    }
    for (auto i : people) {
        if (i.second > 0) return i.first;
    }
}