#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs(int &answer, int start, int target, map<int, vector<int>> family, vector<vector<bool>>& visited, int count, int M){
    if (start == target){
        answer = count;
        return;
    }

    for (auto f : family[start]){
        if (visited[start][f] == true)
            continue;
                
        visited[start][f] = true;
        visited[f][start] = true;

        dfs(answer, f, target, family, visited, count + 1, M);
    }

    return;
}

int main(){
    // 입력: 전체 사람의 수
    int N;
    cin >> N;

    // 입력: 촌수를 계산할 두 사람
    vector<int> target(2, 0);
    for (int i = 0; i < 2; i++) cin >> target[i];

    // 입력: 부모 자식의 관계 개수
    int M;
    cin >> M;

    // 입력: 부모 자식간의 관계 (x, y)
    map<int, vector<int>> family;
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));

    for (int j = 0; j < M; j++){
        int parent, child;

        cin >> parent >> child;

        family[child].push_back(parent);
        family[parent].push_back(child);
    }
    
    // DFS: 자식에서 부모로 몇 번 탐색해야 목표를 달성하는지
    int answer = -1;

    dfs(answer, target[0], target[1], family, visited, 0, M);

    cout << answer;
}