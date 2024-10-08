#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> unique(nums.begin(), nums.end());

    int max = nums.size() / 2;

    return min(static_cast<int>(unique.size()), max);
}