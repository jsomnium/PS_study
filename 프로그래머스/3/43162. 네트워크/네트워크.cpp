#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (i == j || computers[i][j] == 0) continue;
            
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    
    queue<int> q;
    vector<bool> visited(n, false);
    int answer = 0;
    
    for (int cmp = 0; cmp < n; ++cmp){
        if (visited[cmp]) continue;
        
        q.push(cmp);
        answer++;
        while(!q.empty()){
            int front = q.front(); q.pop();
            
            for (auto c : adj[front]){
                if (visited[c]) continue;
                visited[c] = true;
                q.push(c);
            }
        }
    }
    
    return answer;
}