#include <iostream>
#include <vector>
#include <queue>
#include <string> // 문자열 입력을 위해 추가

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int bfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int M, int N) {
    queue<pair<pair<int, int>, int>> q;
    
    // 시작점 (0, 0), 시작위치도 칸을 센다
    q.push({{0, 0}, 1});
    visited[0][0] = true;
    
    while(!q.empty()){
        int curRow = q.front().first.first;
        int curCol = q.front().first.second;
        int count = q.front().second;
        q.pop();
        
        // 목표 지점 도달 시 리턴
        if (curRow == M - 1 && curCol == N - 1) return count;
        
        for (int d = 0; d < 4; d++){
            int nextRow = curRow + dr[d];
            int nextCol = curCol + dc[d];
            
            // 맵 범위 내에 있고, 길(1)이며, 방문하지 않은 경우
            if (nextRow >= 0 && nextRow < M && nextCol >= 0 && nextCol < N) {
                if (map[nextRow][nextCol] == 1 && !visited[nextRow][nextCol]){
                    visited[nextRow][nextCol] = true; // 방문 표시
                    q.push({{nextRow, nextCol}, count + 1});
                }
            }
        }
    }
    return -1; // 도달할 수 없는 경우
}

int main() {
    int N, M;
    if (!(cin >> M >> N)) return 0; // 행 M, 열 N 입력
    
    vector<vector<int>> map(M, vector<int>(N, 0));
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    
    // 미로 입력 (숫자가 붙어서 들어오는 경우를 대비해 string 사용 권장)
    for (int i = 0; i < M; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++) {
            map[i][j] = line[j] - '0'; // 문자를 숫자로 변환
        }
    }
    
    // 결과 출력
    cout << bfs(map, visited, M, N) << endl;
    
    return 0;
}