#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    for (auto str : s){
        if (str == '(') st.push(')');
        else if (str == ')'){
            if (st.empty()) return false;
            else {
                st.pop();
            }
        }
    }
    
    if (!st.empty()) return false;
    
    return true;
}