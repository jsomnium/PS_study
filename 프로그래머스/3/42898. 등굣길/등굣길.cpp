#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    // 가로가 m, 세로가 n 이면 열이 m개, 행이 n개이다
    vector<vector<int>> dp(n+1, vector(m+1, 0)); // m x n 배열
    
    // 집 (시작점)
    dp[1][1] = 1;
    
    // 웅덩이
    for (auto p : puddles){
        dp[p[1]][p[0]] = -1;
    }
    
    // dp 구하기
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (i == 1 && j == 1) continue;
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
        }
    }
    
    return dp[n][m];
}