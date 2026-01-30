#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    // 1번 인덱스부터 사용하기 위해 (n+1) x (m+1) 크기 할당 (행: n, 열: m)
    // 0으로 초기화하여 웅덩이 처리를 편하게 합니다.
    vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));

    // 웅덩이 설정 (좌표 주의: 문제에서 x가 열, y가 행인 경우가 많음)
    for (auto p : puddles) {
        DP[p[1]][p[0]] = -1; // 웅덩이는 -1로 표시
    }

    DP[1][1] = 1; // 시작점

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue; // 시작점은 스킵
            
            if (DP[i][j] == -1) { // 현재 칸이 웅덩이면
                DP[i][j] = 0;     // 경로 수를 0으로 만들고 통과
                continue;
            }

            // 위쪽 칸과 왼쪽 칸의 경로 수를 더함 (나머지 연산 필수!)
            int fromUp = DP[i-1][j];
            int fromLeft = DP[i][j-1];
            DP[i][j] = (fromUp + fromLeft) % 1000000007;
        }
    }

    return DP[n][m];
}