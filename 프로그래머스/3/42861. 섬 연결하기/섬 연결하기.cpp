#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int getParent(vector<int>& parent, int node){
    if (parent[node] == node) return node;

    // 최상위 부모 노드를 찾고 동시에 갱신한다
    return parent[node] = getParent(parent, parent[node]);
}

void unionParent(vector<int>& parent, int startNode, int endNode){
    int rootA = getParent(parent, startNode);
    int rootB = getParent(parent, endNode);
    
    if (rootA < rootB) parent[rootB] = rootA;
    else parent[rootA] = rootB;
}

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> parent;
    
    // parent 배열 초기화
    for (int i = 0; i < n; i++) parent.push_back(i);
    
    // 비용 기준 오름차순 정렬
    sort(costs.begin(), costs.end(), cmp);
    
    // 모든 간선을 돌면서 연결 가능하면 연결한다
    for (int i = 0; i < costs.size(); i++){
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
