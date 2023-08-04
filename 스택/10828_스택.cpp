#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> stk;

int main(){
    int N;
    if(N<1 || N>10000)
        return 0;
    while (N--){
        string str;
        cin >> str;
        if (str == "push"){
            int push_num;
            cin >> push_num;
            stk.push(push_num);
        }
        else if (str == "top"){
            if (!stk.empty()){
            cout << stk.top() << endl;
            } else {
                cout << "-1" << endl;
            }
        }
        else if (str == "size"){
            cout << stk.size() << endl;
        }
        else if (str == "empty"){
            if (stk.empty() == true) cout << "1" << endl;
            else cout << "0" << endl;
        }
        else if (str == "pop"){
            if (!stk.empty()){
                cout << stk.top() << endl;
                stk.pop();
            } else {
                cout << "-1" << endl;
            }
        }
    }
}