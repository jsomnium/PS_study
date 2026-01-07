#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

vector<int> graph[101];
bool visited[101];

int dfs(int node){
    visited[node] = true;
    int count = 1;
    
    for (int next : graph[node]){
        if (!visited[next]){
            count += dfs(next);
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n; // 최대 차이값은 n
    
    for (int i = 0; i < wires.size(); i++){
        for (int j = 1; j <= n; j++){
            graph[j].clear();
        }
    
        for (int j = 0; j < wires.size(); j++){
            if (i==j) continue;
            int a = wires[j][0];
            int b = wires[j][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            }

        memset(visited, false, sizeof(visited));
        int group1 = dfs(1);
        int group2 = n - group1;

        answer = min(answer, abs(group1 - group2));
    }
    
    return answer;
}
