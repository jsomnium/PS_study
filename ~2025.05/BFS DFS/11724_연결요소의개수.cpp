// 문제: 연결 요소의 개수
// 유형: 그래프 탐색
// 난이도: 실버2

#include <iostream>
using namespace std;

int map[1001][1001];
bool visited[1001];
int n, m, result;

void dfs(int num){ // 연결된 곳이 없다면 탐색 종료료
    visited[num] = true;
    for (int i = 1; i <= n; i++){
        if (map[num][i] && !visited[i])
            dfs(i);
    }
}

int main(){
    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        map[a][b] = 1; // 양방향으로 간선만들어주기
        map[b][a] = 1;
    }

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            result++;
            dfs(i);
        }
    }
    cout << result << '\n';

    return 0;
}