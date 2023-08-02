#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack<int>stk;
    string ans;
    int increasing = 1; // 오름차순 기록용으로, 1부터 시작하므로 1로 초기화한다.
    int size; // 만들고 싶은 수열의 크기
    int num; // 출력하고 싶은 수

    while (size--){
        cin >> num;
        if (num < increasing){ // num = increasing이 될 때 까지 반복
            ans += '+';
            stk.push(increasing);
            increasing++; // 스택에 넣었으므로 1 증가
        } else if (num = increasing){
            ans += '-';
            stk.pop();
        } else {
            ans = 'NO';
            stk.push(100001);
        }
    }
    
    cout << ans;
}