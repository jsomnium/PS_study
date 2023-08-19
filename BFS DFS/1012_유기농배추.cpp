// 문제: 유기농 배추
// 유형: DFS
// 난이도: 실버2

#include <iostream>
using namespace std;

// * 참고
// 1인 경우에 방문을 완료하면 0으로 바꾸면 되므로
// visited도 필요없고, 초기화 할 필요도 없다

bool map[50][50];

void dfs(int row, int col){
    if (row < 0 || row >= 50 || col < 0 || col >= 50) // 범위 초과시 종료
        return;

    // 이미 검사했거나 땅이 아닐 경우 제외
    if (!map[row][col])
        return;

    // 검사했다고 표시
    map[row][col] = false;

    dfs(row + 1, col); // 상
    dfs(row - 1, col); // 하
    dfs(row, col - 1); // 좌
    dfs(row, col + 1); // 우
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int TestCase;
    cin >> TestCase;

    while (TestCase--){
        int m, n, k;
        cin >> m >> n >> k;

        for (int i = 0; i < k; i++){ // 배추 입력받기
            int x, y;
            cin >> x >> y;
            map[y][x] = true;
        }

        int ans = 0;
        for (int row = 0; row < n; row++){ // 탐색 시작
            for (int col = 0; col < m; col++){
                if (map[row][col]){
                    // 1인 경우 하나를 발견하면
                    // 인접한 곳을 모두 0으로 만들고, 정답 +1 을 한다.
                    ans++;
                    dfs(row, col);
                }
            }
        }

        cout << ans << '\n';
    }
}