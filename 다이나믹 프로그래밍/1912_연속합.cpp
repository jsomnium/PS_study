// 문제: 연속합
// 유형: 다이나믹 프로그래밍
// 난이도: 실버2

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int arr[1000001];
    int dp[1000001];

    cin >> n; // 수의 개수
    
    for (int i = 0; i < n; i++){ // 수열 입력받기
        cin >> arr[i];
        dp[i] = arr[i];
    }

    int ans = arr[0];

    for (int i = 1; i < n; i++){
        dp[i] = max(dp[i], dp[i-1] + arr[i]); // (현재 수)와 (이전까지의 최댓값 + 현재 수) 중 더 큰 것을 반환
        ans = max(ans, dp[i]); // 가장 큰 수를 반환
    }
    
    cout << ans;
}