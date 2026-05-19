#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxSheep = 0;
vector<vector<int>> tree;

void dfs(int curr, int sheep, int wolf, vector<int> nextNodes, const vector<int>& info) {
    if (info[curr] == 0) sheep++;
    else wolf++;

    // 가지치기(Pruning): 늑대가 양과 같거나 많아지면 더 이상 전진 불가
    if (wolf >= sheep) {
        return;
    }

    // 3. 최댓값 갱신
    maxSheep = max(maxSheep, sheep);

    // 4. 다음 단계를 위한 후보군 목록 업데이트
    vector<int> updatedNodes = nextNodes;
    
    // 4-1. 방금 방문한 현재 노드(curr)는 후보군에서 제외
    for (auto it = updatedNodes.begin(); it != updatedNodes.end(); ++it) {
        if (*it == curr) {
            updatedNodes.erase(it);
            break;
        }
    }

    // 4-2. 현재 노드의 자식 노드들이 있다면 새로운 후보군에 추가
    for (int child : tree[curr]) {
        updatedNodes.push_back(child);
    }

    // 5. 업데이트된 후보군에 있는 모든 노드를 for문으로 하나씩 방문해보기 (완전 탐색)
    for (int next : updatedNodes) {
        dfs(next, sheep, wolf, updatedNodes, info);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    maxSheep = 0; // 전역 변수 초기화
    tree.assign(n, vector<int>());

    // 부모 -> 자식 방향으로만 트리 구성 (인접 리스트)
    for (const auto& edge : edges) {
        int parent = edge[0];
        int child = edge[1];
        tree[parent].push_back(child);
    }

    vector<int> startNodes = {0};
    
    dfs(0, 0, 0, startNodes, info);

    return maxSheep;
}