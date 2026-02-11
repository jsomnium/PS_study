#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main(){
    // N x M 사이즈이므로, 행이 M개 열이 N개이다
    int N, M;
    cin >> M >> N;
    vector<vector<int>> map (M, vector(N, 0));
    vector<vector<bool>> visited (M, vector(N, false));
    
    // 각각의 수들은 붙어서 들어오므로, string으로 입력받아 처리한다
    for (int i = 0; i < M; i++){
        string s = "";
        cin >> s;
        
        // 문자를 숫자로 변환
        for (int j = 0; j < N; j++){
            map[i][j] = s[j] - '0';
        }
    }
    
    // BFS: (0, 0)에서 (N, M)으로 가는 최소 거리를 구한다
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visited[0][0] = true;
    
    while (!q.empty()){
        int curRow = q.front().first.first;
        int curCol = q.front().first.second;
        int count = q.front().second;
        q.pop();
        
        if (curRow == M - 1 && curCol == N - 1){
            cout << count << endl;
            return 0;
        }
        
        for (int d = 0; d < 4; d++){
            int nextRow = curRow + dr[d];
            int nextCol = curCol + dc[d];
            
            if (nextRow >= 0 && nextCol >= 0 && nextRow < M && nextCol < N && map[nextRow][nextCol] == 1 && visited[nextRow][nextCol] == false){
                visited[nextRow][nextCol] = true;
                q.push({{nextRow, nextCol}, count + 1});
            }
        }
    }
    
    return -1;
}