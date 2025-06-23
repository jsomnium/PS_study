// 문제: 01타일
// 유형: 다이나믹 프로그래밍
// 난이도: 실버3

#include <iostream>
#include <algorithm>
#define M 15746
using namespace std;

int main(){
    int N;
    int dp[1000001];
    cin >> N;

    dp[1] = 1; // 1
    dp[2] = 2; // 00, 11

    for(int i = 3; i <= N; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % M;
        // 맨 앞에 올 자리가 한칸 남았을 경우, 두 칸 남았을 경우를 더해주면 된다.

    cout << dp[N];

}