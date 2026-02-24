#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int k, vector<vector<bool>>& visited, vector<vector<int>>& map, int curX, int curY, int N){
    for (int d = 0; d < 4; d++){
        int nextX = curX + dx[d];
        int nextY = curY + dy[d];

        if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && visited[nextX][nextY] == false &&map[nextX][nextY] > k){
            visited[nextX][nextY] = true;
            dfs(k, visited, map, nextX, nextY, N);
        }
    }
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> map(N, vector<int>(N, 0));

    int maxNum = 0;
    int minNum = 101; 
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
            maxNum = max(maxNum, map[i][j]);
            minNum = min(minNum, map[i][j]);
        }
    }

    int answer = 1; // 물에 잠기지 않는 영역 최대

    for (int k = minNum; k < maxNum; k++){
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        int temp = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // 아직 방문 안 했고, 물에 잠기지 않는 높이라면 새로운 영역 발견!
                if (map[i][j] > k && !visited[i][j]) {
                    temp++; 
                    visited[i][j] = true;
                    dfs(k, visited, map, i, j, N); // 연결된 모든 안전 지점 방문처리
                }
            }
        }
        answer = max(answer, temp);
        }

    cout << answer << endl;
    return 0;
}