// 문제: 연결 요소의 개수
// 유형: 그래프 탐색
// 난이도: 실버2

#include <iostream>
using namespace std;

int N, M, ans;
int arr[1001][1001]; // 인접 리스트

void DFS(int x, int y){
    if(arr[x][y] == 1){
        arr[x][y] = 0;
        arr[y][x] = 0;
        for (int i = 1; i < N; i++){
            DFS(x, y + i);
        }
    }
    else return;
}

int main(){

    cin >> N >> M;

    for (int i = 1; i <= M; i++){ // 인접 리스트 입력받기
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; i++){
            if (arr[i][j] == 1){
                DFS(i, j);
                ans += 1;
            }
        }
    }

    cout << ans;
}