// 문제: 토마토
// 유형: 그래프 탐색
// 난이도: 골드5

// 1. 토마토를 입력받고, 1이면 바로 큐에 넣고 방문 체크를 한다.
// 2. 이후 큐에 들어있는 것들을 기준으로 BFS 탐색을 시작한다.
//    한번 할 떄 마다 cnt 증가
// 3. x, y, z 방향으로 하나씩 이동해서 탐색하다가, 큐가 비면 종료

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m, h;
int tomato[102][102][102];
int dz[6] = {0, 0, 0, 0, -1, 1};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};

int dist[102][102][102];
int day = 0;

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> m >> n >> h;
    queue<pair<pair<int, int>, int>> Q;

    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1)
                    Q.push({{i, j}, k});
                if (tomato[i][j][k] == 0)
                    dist[i][j][k] = -1;
            }
        }
    }
    while (!Q.empty()){
        pair<pair<int, int>, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 6; i++){
            int nz = cur.first.first + dz[i];
            int nx = cur.first.second + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue;
            if (dist[nz][nx][ny] >= 0)
                continue;
            dist[nz][nx][ny] = dist[cur.first.first][cur.first.second][cur.second] + 1;
            Q.push({{nz, nx}, ny});
        }
    }
    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                if (dist[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                day = max(day, dist[i][j][k]);
            }
        }
    }
    cout << day;
}