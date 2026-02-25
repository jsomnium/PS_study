#include <iostream>
#include <vector>
using namespace std;

// 북, 동, 남, 서
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int cnt = 0;

void dfs(vector<vector<int>>& Map, int curRow, int curCol, int curDir){
    if (Map[curRow][curCol] == 0) {
        Map[curRow][curCol] = 2; // 청소 완료
        cnt++;
    }

    // 주변 4칸 중 청소되지 않은 빈 칸이 있는지 확인
    for (int i = 0; i < 4; i++) {
        // 왼쪽 방향으로 회전
        curDir = (curDir + 3) % 4; 
        
        int nextRow = curRow + dr[curDir];
        int nextCol = curCol + dc[curDir];

        // 청소되지 않은 빈 칸이 있다면 전진
        if (Map[nextRow][nextCol] == 0) {
            dfs(Map, nextRow, nextCol, curDir);
            return; // 전진했다면 거기서 끝 (다시 1번으로)
        }
    }

    // 3. 네 방향 모두 청소되었거나 벽인 경우
    int backDir = (curDir + 2) % 4; // 후진 방향
    int backRow = curRow + dr[backDir];
    int backCol = curCol + dc[backDir];

    if (Map[backRow][backCol] != 1) { // 뒤가 벽이 아니면 후진
        dfs(Map, backRow, backCol, curDir); // 바라보는 방향은 유지
    } else {
        // 뒤가 벽이면 작동 중지
        cout << cnt << endl;
        exit(0); // 프로그램 종료
    }
}

// 청소하는 영역의 개수 구하기
int main(){
    int N, M;
    cin >> N >> M;

    vector<int> Robot(3, 0);
    cin >> Robot[0] >> Robot[1] >> Robot[2];
    // 좌표R, 좌표C, 방향D

    vector<vector<int>> Map(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> Map[i][j];
        }
    }

    dfs(Map, Robot[0], Robot[1], Robot[2]);

    return 0;
}