#include <string>
#include <vector>
#include <queue>
using namespace std;

int cnt = 0;

void bfs(int node, vector<vector<int>> computers, vector<bool>& visited){
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()){
        int front = q.front();
        q.pop();
        
        // 연결할 수 있는 것을 다음 큐에 담기
        for (int i = 0; i < computers.size(); i++){
            if (computers[front][i] == 1 && front != i && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false); // 방문 여부 확인
    
    for (int i = 0; i < n; i++){
        if (visited[i]) continue;
        
        bfs(i, computers, visited);
        cnt++;
    }
    
    return cnt;
}