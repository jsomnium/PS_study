#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool isConnected (string a, string b){
    int diff = 0;
    
    if (a.size() != b.size()) return false;
    
    for (int i = 0; i < a.size() && diff <= 1; ++i){
        if (a[i] != b[i]) diff++;
    }
    
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    int n = words.size();

    // 인접 리스트 구성
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (isConnected(words[i], words[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }

    // target 인덱스 찾기
    int targetIdx = -1;
    for (int i = 0; i < n; i++)
        if (words[i] == target) { targetIdx = i; break; }
    if (targetIdx == -1) return 0;

    // BFS
    int beginIdx = n - 1;
    vector<bool> visited(n, false);
    queue<pair<int,int>> q;
    q.push({beginIdx, 0});
    visited[beginIdx] = true;

    while (!q.empty()) {
        auto [cur, depth] = q.front(); q.pop();
        if (cur == targetIdx) return depth;
        for (int next : adj[cur])
            if (!visited[next]) {
                visited[next] = true;
                q.push({next, depth + 1});
            }
    }
    return 0;
}