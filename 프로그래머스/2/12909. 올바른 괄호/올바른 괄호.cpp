#include<string>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    queue<char> Q;
    
    for (int i = 0; i < s.length(); i++){
        if (Q.empty() && s[i] == ')'){
            return false;
        }
        else if (s[i] == '('){
            Q.push(s[i]);
        } else {
            Q.pop();
        }
    }
    
    if (Q.empty()){
        return true;
    } else
        return false;
}