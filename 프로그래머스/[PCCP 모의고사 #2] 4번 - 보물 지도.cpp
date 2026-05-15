#include <vector>
#include <queue>

using namespace std;

struct State {
    int y, x, dist;
    bool jumped;
};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

// visited[row][col][jumped_status]
bool visited[1001][1001][2];

int solution(int n, int m, vector<vector<int>> hole) {
    // 문제의 n, m이 가로, 세로이므로 배열 인덱스 주의 (m: 행, n: 열)
    vector<vector<int>> board(m + 1, vector<int>(n + 1, 0));
    for (auto h : hole) {
        board[h[1]][h[0]] = 1; 
    }

    queue<State> q;
    q.push({1, 1, 0, false});
    visited[1][1][0] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.y == m && cur.x == n) {
            return cur.dist;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (ny >= 1 && ny <= m && nx >= 1 && nx <= n && !board[ny][nx]) {
                if (!visited[ny][nx][cur.jumped]) {
                    visited[ny][nx][cur.jumped] = true;
                    q.push({ny, nx, cur.dist + 1, cur.jumped});
                }
            }

            // 마법 신발 사용 (2칸 점프)
            if (!cur.jumped) {
                int nny = cur.y + (dy[i] * 2);
                int nnx = cur.x + (dx[i] * 2);

                if (nny >= 1 && nny <= m && nnx >= 1 && nnx <= n && !board[nny][nnx]) {
                    if (!visited[nny][nnx][1]) {
                        visited[nny][nnx][1] = true;
                        q.push({nny, nnx, cur.dist + 1, true});
                    }
                }
            }
        }
    }

    return -1;
}
