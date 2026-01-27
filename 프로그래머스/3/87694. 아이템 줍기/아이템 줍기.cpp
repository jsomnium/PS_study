#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// 전역 변수 초기화
vector<vector<int>> board(102, vector<int>(102, 0));
vector<vector<int>> dist(102, vector<int>(102, -1));

int bfs(int startX, int startY, int targetX, int targetY){
    queue<pair<int, int>> q;
    q.push({startX, startY});
    dist[startY][startX] = 0; // 시작점 거리 초기화 (y, x 순서 주의)
    
    while (!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        if (curX == targetX && curY == targetY){
            return dist[curY][curX] / 2; // 세미콜론 추가 및 2배 확장했으므로 2로 나눔
        }
        
        for (int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= 102 || ny >= 102) continue;
            
            // 테두리(1)이고 방문하지 않은(-1) 경우만 이동
            if (board[ny][nx] == 1 && dist[ny][nx] == -1){
                dist[ny][nx] = dist[curY][curX] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 좌표 2배 확장
    characterX *= 2; characterY *= 2; itemX *= 2; itemY *= 2;
    
    for (auto r : rectangle){
        int x1 = r[0] * 2, y1 = r[1] * 2, x2 = r[2] * 2, y2 = r[3] * 2;
        for (int i = y1; i <= y2; i++){
            for (int j = x1; j <= x2; j++){
                board[i][j] = 1; // 일단 직사각형 영역을 모두 1로 채움
            }
        }
    }
    
    for (auto r : rectangle){
        int x1 = r[0] * 2, y1 = r[1] * 2, x2 = r[2] * 2, y2 = r[3] * 2;
        for (int i = y1 + 1; i < y2; i++){
            for (int j = x1 + 1; j < x2; j++){
                board[i][j] = 0; // 내부는 다시 0으로 비워 테두리만 남김
            }
        }
    }
    
    return bfs(characterX, characterY, itemX, itemY);
}