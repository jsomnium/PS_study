#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int N; // 입력받을 수의 개수 N개
    cin >> N;
    stack<int> s; // 마지막에 들어온 수를 삭제해야 하므로 stack 사용
    
    while (N--){
        int num;
        cin >> num;
        if (num == 0){
            s.pop();
        } else {
            s.push(num);
        }
    }
    int ans = 0;
    while (!s.empty())
    {
        ans = ans + s.top();
        s.pop();
    }
    cout << ans;
}