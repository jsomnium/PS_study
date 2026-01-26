#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited(201, false);

int bfs(int net, vector<vector<int>> graph){
    queue<int> q;
    q.push(net);
    
    while (!q.empty()){
        int front = q.front();
        q.pop();
        
        for (int computer : graph[front]){
            if (visited[computer]) continue;
            q.push(computer);
            visited[computer] = true;
        }
    }
    
    return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<int>> graph(n);
    
    // 인접그래프 생성
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            if (computers[i][j] == 1) graph[i].push_back(j);
        }
    }
    
    // 모든 점을 방문할 때 까지 진행
    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;
        answer += bfs(i, graph);
    }
    
    return answer;
}