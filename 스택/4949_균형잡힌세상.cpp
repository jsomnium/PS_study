#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    while (true){
        string s={""};
        stack<char> stk;
        bool ans = true;
        getline(cin,s); // 공백까지 입력받아야 하므로 getline을 사용한다.
        if (s[0]=='.') break; // .만 입력받았을 경우에는 break
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '(' || s[i] == '['){
                stk.push(s[i]); // 왼쪽 괄호는 무조건 push
            } else if (s[i] == ')'){
                if (!stk.empty() && stk.top() == '('){
                    stk.pop(); // (1) 스택이 비어있지 않고 (2) top이 (왼쪽) 괄호인 경우 pop
                } else {
                    ans = false;
                    break;
                }
            } else if (s[i] == ']'){
                if (!stk.empty() && stk.top() == '['){
                    stk.pop(); // (1) 스택이 비어있지 않고 (2) top이 [왼쪽] 괄호인 경우 pop
                } else {
                    ans = false;
                    break;
                }
            }
        }
        if (stk.empty() && ans == true) cout << "yes" << endl; // (1) 스택이 비어있고 (2) ans가 false로 변환되지 않고 그대로 true인 경우
        else cout << "no" << endl;
    }
    return 0;
}