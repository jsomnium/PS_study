// 문제: 파도반 수열
// 유형: 다이나믹 프로그래밍
// 난이도: 실버3

#include <iostream>
using namespace std;

int main(){
    int T;
    long long dp[101] = {0, };
    // 피보나치 수열의 값은 N이 커짐에 따라 빠르게 증가하므로
    // long long 자료형을 사용해야한다.

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;

    for (int i = 5; i <= 100; i++)
            dp[i] = dp[i-2] + dp[i-3];

    cin >> T;
    while (T--){
        int N;
        cin >> N;
        cout << dp[N] << "\n";
    }


}