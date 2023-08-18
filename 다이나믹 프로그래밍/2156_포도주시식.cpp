// 문제: 포도주 시식
// 유형: 다이나믹 프로그래밍
// 난이도: 실버1

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; // n개의 포도주 잔
    int arr[100001]; // 포도주의 양
    int dp[100001];

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for (int i = 3; i <= n; i++){
        dp[i] = max({dp[i-3]+arr[i-1]+arr[i], dp[i-2]+arr[i], dp[i-1]});
    }
    
    cout << dp[n];
}