// 문제: 바이러스
// 유형: BFS, DFS, 그래프 이론, 그래프 탐색
// 난이도: 실버3

#include <iostream>
#include <queue>
using namespace std;
 
int V, E; // 노드의 개수, 간선의 개수
int arr[101][101] = { 0, }; // 인접 행렬
bool visited[101] = { 0, }; // 방문 여부
int ans = 0; // 정답 count
queue<int> q;
 
void BFS(int v) {
    visited[v] = true;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 1; i <= V; i++) {
            if (visited[i] == 0 && arr[v][i] == 1) {
                q.push(i);
                visited[i] = true;
                ans++; // 노드 방문시 카운트 증가
            }
        }
    }
}
 
int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1; // 인접 행렬 1로 초기화
        arr[b][a] = 1;
    }
 
    BFS(1); // 1번 컴퓨터부터 시작
    cout << ans;
}