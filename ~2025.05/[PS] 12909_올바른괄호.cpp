#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;

    for (char c : s) {
        if (c == '(')
            stk.push(c);
        else if (c == ')') {
            if (stk.empty())
                return false;
            else
                stk.pop();
        }
    }

    return stk.empty();
  // answer 가 아닌, stk.empty() 를 return
}
