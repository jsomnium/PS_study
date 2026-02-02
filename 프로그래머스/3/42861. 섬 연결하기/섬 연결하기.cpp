#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int getParent(vector<int>& parent, int node){
    // 최상위 노드라면 바로 반환
    if (parent[node] == node) return node;
    
    return parent[node] = getParent(parent, parent[node]);
}

void unionParent(vector<int>& parent, int startNode, int endNode){
    int rootA = getParent(parent, startNode);
    int rootB = getParent(parent, endNode);
    
    if (rootA < rootB) parent[rootB] = rootA;
    else parent[rootA] = rootB;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<int> parent(n, -1);
    for (int i = 0; i < n; i++) parent[i] = i;
    
    sort(costs.begin(), costs.end(), cmp); // 비용이 가장 작은 것 부터 정렬
    
    // 모든 간선을 돌면서 연결 가능하면 연결한다
    for (int i = 0; i < costs.size(); ++i){
        int startNode = costs[i][0];
        int endNode = costs[i][1];
        
        // 연결하려는 노드들의 부모가 다른 경우,
        // 부모를 합치고 비용을 더한다
        if (getParent(parent, startNode) == getParent(parent, endNode)) continue;
        
        unionParent(parent, startNode, endNode);
        answer += costs[i][2];
    }
    
    return answer;
}