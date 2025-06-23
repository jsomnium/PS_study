// 문제: 2xn 타일링
// 유형: 다이나믹 프로그래밍
// 난이도: 실버3

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int DP[1001];
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;
    for (int i = 4; i <= n; i++){
        DP[i] = (DP[i-1] + DP[i-2]) % 10007;
    }
    cout << DP[n];
}