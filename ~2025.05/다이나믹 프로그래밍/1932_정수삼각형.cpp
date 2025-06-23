#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t[501][501]={0};
    int dp[501][501] = {0};
    int ans = -1;
    int n;

    cin >> n;

    int idx = 1;
    for (int i = 1; i <= n; i++){ // 정수 입력받기
        for (int j = 1; j <= i;j++)
            cin >> t[i][j];
    }

    dp[1][1] = t[1][1]; // 첫번째 줄은 예외로 선언하기
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= i;j++){
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + t[i][j];
            // 왼쪽 위, 바로 위 중 더 큰 것과 자신을 더하기
        }
    }
    for (int i = 1; i <= n;i++){ // 가장 큰 것 구하기
        if(ans < dp[n][i])
            ans = dp[n][i];
    }
    cout << ans;
    return 0;
}