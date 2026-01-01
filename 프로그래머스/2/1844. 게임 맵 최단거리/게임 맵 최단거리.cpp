#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int bfs(const vector<vector<int>>& maps, int maxRow, int maxCol) {
    // 각 칸까지의 최단 거리를 저장하는 배열. -1은 아직 방문하지 않았음을 의미.
    // 0번 인덱스부터 시작하므로 maps의 실제 크기와 동일하게 초기화
    vector<vector<int>> distances(maxRow, vector<int>(maxCol, -1));

    // 큐: {현재까지의 이동 거리, {현재 행, 현재 열}}
    queue<pair<int, pair<int, int>>> q;

    // 시작 지점 (0,0) 큐에 추가 및 거리 초기화
    q.push({1, {0, 0}}); // 시작 지점까지의 거리는 1 (첫 칸 포함)
    distances[0][0] = 1; // 방문 처리와 동시에 거리 기록

    while (!q.empty()) {
        int current_dist = q.front().first;
        int r = q.front().second.first; // 현재 행
        int c = q.front().second.second; // 현재 열
        q.pop();

        // 목적지 (maxRow-1, maxCol-1)에 도달했는지 확인
        if (r == maxRow - 1 && c == maxCol - 1) {
            return current_dist; // 최단 거리 반환
        }

        // 상하좌우 4방향 탐색
        for (int i = 0; i < 4; ++i) {
            int nextR = r + dr[i];
            int nextC = c + dc[i];

            // 1. 맵의 유효한 범위 내에 있는지 체크
            // 2. 다음 칸이 벽이 아닌 길인지 (maps[nextR][nextC] == 1)
            // 3. 아직 방문하지 않았거나(distances[nextR][nextC] == -1), 
            //    현재 경로가 더 짧은지(이 문제에서는 첫 방문이 최단거리이므로 -1 체크만 해도 됨)
            if (nextR >= 0 && nextR < maxRow && nextC >= 0 && nextC < maxCol &&
                maps[nextR][nextC] == 1 && distances[nextR][nextC] == -1) {
                
                distances[nextR][nextC] = current_dist + 1; // 거리 업데이트
                q.push({current_dist + 1, {nextR, nextC}}); // 큐에 추가
            }
        }
    }

    // 큐가 비워질 때까지 목적지에 도달하지 못했다면 -1 반환
    return -1;
}

// solution 함수는 bfs 함수를 호출하여 결과를 반환
int solution(vector<vector<int>> maps)
{
    // n * m 크기이므로 행이 m개 열이 n개
    int maxRow = maps.size();
    int maxCol = maps[0].size();

    return bfs(maps, maxRow, maxCol);
}