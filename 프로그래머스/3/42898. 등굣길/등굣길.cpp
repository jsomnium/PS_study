#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    const int MOD = 1000000007;
    
    // 세로(n) x 가로(m) 배열 생성
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[1][1] = 1;

    // 웅덩이 위치를 미리 표시
    for (auto p : puddles) {
        int x = p[0];
        int y = p[1];
        dp[y][x] = -1; // 웅덩이는 -1로 표시
    }

    // dp 채우기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] == -1) {
                dp[i][j] = 0; // 웅덩이 다시 0으로
                continue;
            }

            if (i > 1)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j > 1)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }

    return dp[n][m];
}
