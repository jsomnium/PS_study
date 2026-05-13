#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int networkCnt = 0;
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && computers[i][j] == 1)
                adj[i].push_back(j);
    
    vector<bool> visited(n, false);
    queue<int> q;
    
    for (int i = 0; i < n; i++){
        if (visited[i]) continue;
        
        q.push(i);
        visited[i] = true;
        
        while (!q.empty()){
            int front = q.front();
            q.pop();
            
            for (auto a : adj[front]){
                if (visited[a]) continue;
                visited[a] = true;
                q.push(a);
            }
        }
        
        networkCnt++;
    }
    
    return networkCnt;
}