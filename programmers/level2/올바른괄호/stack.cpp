#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stack;
    for (auto c : s) {
        if (!stack.empty()) {
            if (stack.top() == '(' && c == ')') {
                stack.pop();
            } else {
            	stack.push(c);
            }
        } else {
            stack.push(c);
        }
    }
    
    if (stack.empty()) return true;
    return false;
}