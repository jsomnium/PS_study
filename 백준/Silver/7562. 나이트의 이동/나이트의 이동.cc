#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 나이트가 이동할 수 있는 8가지 방향
int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

struct Point {
    int r, c, dist;
};

// [Service Layer] 최소 이동 횟수를 계산하는 로직 분리
int solve() {
    int L;
    cin >> L;

    int curRow, curCol, goalRow, goalCol;
    cin >> curRow >> curCol >> goalRow >> goalCol;

    // 이미 목표 지점에 있는 경우
    if (curRow == goalRow && curCol == goalCol) return 0;

    vector<vector<bool>> visited(L, vector<bool>(L, false));
    queue<Point> q;

    q.push({curRow, curCol, 0});
    visited[curRow][curCol] = true;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            // 맵 범위 내에 있고 방문하지 않은 경우
            if (nr >= 0 && nr < L && nc >= 0 && nc < L && !visited[nr][nc]) {
                if (nr == goalRow && nc == goalCol) return cur.dist + 1;
                
                visited[nr][nc] = true;
                q.push({nr, nc, cur.dist + 1});
            }
        }
    }
    return 0;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcase;
    cin >> testcase;

    while (testcase--) {
        cout << solve() << "\n";
    }

    return 0;
}