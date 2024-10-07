#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> closet;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for (auto i : clothes) {
        closet[i[1]]++;
    }
    for (auto i : closet) {
        answer *= (i.second + 1);
    }
    return answer - 1;
}