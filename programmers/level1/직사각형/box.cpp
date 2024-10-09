#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_width = 0;
    int max_height = 0;

    for (auto size : sizes) {
        int w = max(size[0], size[1]);
        int h = min(size[0], size[1]);

        max_width = max(max_width, w);
        max_height = max(max_height, h);
    }

    return max_width * max_height;
}