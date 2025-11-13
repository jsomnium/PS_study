#include <string>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAX = 102;
int map[MAX][MAX] = {0};
int dist[MAX][MAX] = {-1};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// 2. bfs에서 dist 파라미터 제거
void bfs(int characterX, int characterY, int itemX, int itemY, int &answer){
    queue<pair<int, int>> q;
    q.push({characterX, characterY});
    
    dist[characterY][characterX] = 0; 

    while (!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        if (cx == itemX && cy == itemY) {
            answer = (dist[cy][cx]) / 2;
            break; 
        }
        
        for (int move = 0; move < 4; move++){
            int nextX = cx + dx[move];
            int nextY = cy + dy[move];
            
            if (nextX < 0 || nextX >= MAX || nextY < 0 || nextY >= MAX) continue;
            
            if (map[nextY][nextX] == 1 && dist[nextY][nextX] == 0){
                dist[nextY][nextX] = dist[cy][cx] + 1; 
                q.push({nextX, nextY});
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;

    for (auto r : rectangle){
        for (int y = 2 * r[1]; y <= 2 * r[3]; y++){
            for (int x = 2 * r[0]; x <= 2 * r[2]; x++){
                map[y][x] = 1;
            }
        }
    }
    
    for (auto r : rectangle){
        for (int y = 2 * r[1] + 1; y < 2 * r[3]; y++){
            for (int x = 2 * r[0] + 1; x < 2 * r[2]; x++){
                map[y][x] = 0;
            }
        }
    }
    
    bfs(characterX, characterY, itemX, itemY, answer);
    
    return answer;
}