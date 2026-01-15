#include <string>
#include <vector>
#include <algorithm> // sort 사용을 위해 필요

using namespace std;

// 1. 부모 노드를 찾는 함수 (Find)
// 경로 압축(Path Compression) 적용
int getParent(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    // 찾은 부모를 바로 갱신하여 경로를 압축함
    return parent[x] = getParent(parent, parent[x]);
}

// 2. 두 노드를 합치는 함수 (Union)
void unionParent(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    // 더 작은 숫자가 부모가 되도록 설정 (관례적)
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

// 3. 간선 정렬을 위한 비교 함수
bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2]; // 비용(2번 인덱스) 기준 오름차순
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    // 부모 테이블 초기화 (0 ~ n-1)
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    // 간선을 비용 기준으로 오름차순 정렬
    sort(costs.begin(), costs.end(), cmp);
    
    // 크루스칼 알고리즘 수행
    for (int i = 0; i < costs.size(); i++) {
        int start = costs[i][0];
        int end = costs[i][1];
        int cost = costs[i][2];
        
        // 두 섬의 부모가 다르면 (사이클이 형성되지 않으면) 연결
        if (getParent(parent, start) != getParent(parent, end)) {
            unionParent(parent, start, end);
            answer += cost;
        }
    }
    
    return answer;
}