#include <iostream>
#include <vector>
using namespace std;

int answer = 0;

// 이동 방향: 북쪽, 동쪽, 남쪽, 서쪽
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(vector<vector<int>>& Map, int curRow, int curCol, int curDir){
    if (Map[curRow][curCol] == 0){
        Map[curRow][curCol] = 2;
        answer++;
    }

    for (int d = 0; d < 4; d++){
        curDir = (curDir + 3) % 4;

        int nextRow = curRow + dr[curDir];
        int nextCol = curCol + dc[curDir];

        if (Map[nextRow][nextCol] == 0){
            dfs(Map, nextRow, nextCol, curDir);
            return;
        }
    }

    int backDir = (curDir + 2) % 4;
    int backRow = curRow + dr[backDir];
    int backCol = curCol + dc[backDir];

    if (Map[backRow][backCol] != 1){
        dfs(Map, backRow, backCol, curDir);
    } else {
        cout << answer << endl;
        exit(0);
    }
}

int main(){
    int R, C;
    cin >> R >> C;

    vector<int> Robot(3, 0);
    cin >> Robot[0] >> Robot[1] >> Robot[2];
    // R, C, D

    vector<vector<int>> Map(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++)
            cin >> Map[i][j];
    }

    dfs(Map, Robot[0], Robot[1], Robot[2]);
}