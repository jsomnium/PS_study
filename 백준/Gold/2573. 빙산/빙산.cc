#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

void dfs(vector<vector<int>>& map, vector<vector<bool>>& visited,
    int curRow, int curCol, int N, int M){
    if (map[curRow][curCol] == 0)
        return;
    
    visited[curRow][curCol] = true;
    for (int d = 0; d < 4; d++){
        int nextRow = curRow + dr[d];
        int nextCol = curCol + dc[d];
        
        // 다음 점 방문 가능 여부 확인
        if (nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < M
            && visited[nextRow][nextCol] == false && map[nextRow][nextCol] > 0){
            dfs(map, visited, nextRow, nextCol, N, M);
        }
    }
}

// 빙산이 두 덩어리 이상으로 분리되는 최초의 시간 구하기
int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> curMap(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> curMap[i][j];

    for (int year = 1; true; year++){
        vector<vector<int>> nextMap(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        // nextMap 만들기
        for (int row = 0; row < N; row++){
            for (int col = 0; col < M; col++){
                if (curMap[row][col] == 0) continue;
                int count = 0;

                // 현재 부분과 인접한 영역에 몇 개의 바다가 있는지 확인
                for (int d = 0; d < 4; d++){
                    int neighborRow = row + dr[d];
                    int neightborCol = col + dc[d];

                    if (curMap[neighborRow][neightborCol] == 0)
                        count++;
                }

                // 인접한 바다 면의 수 만큼 내년도 빙산의 높이 감소
                int nextHeight = curMap[row][col] - count;
                if (nextHeight < 0) nextHeight = 0;
                nextMap[row][col] = nextHeight;
            }
        }

        // 여러 덩어리로 분리되는지 확인
        int icebergCount = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (nextMap[i][j] != 0 && visited[i][j] == false){
                    icebergCount++;
                    dfs(nextMap, visited, i, j, N, M);
                }

                if (icebergCount >= 2){
                    cout << year << endl;
                    return 0;
                }
            }
        }

        if (icebergCount == 0){
            cout << 0 << endl;
            return 0;
        }

        // 분리되지 않는다면, 기존 맵을 nextMap으로 덮어씌우고 다음 년도 탐색 시작
        curMap = nextMap;
    }
}