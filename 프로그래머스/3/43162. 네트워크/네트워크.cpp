#include <string>
#include <vector>
#include <queue> // std::queue 사용

using namespace std;

void bfs(int start_node, int n, vector<vector<int>>& computers, vector<bool>& visited_nodes) {
    queue<int> q;
    q.push(start_node);
    visited_nodes[start_node] = true;
    
    while (!q.empty()) {
        int current_node = q.front();
        q.pop();
        
        for (int neighbor_node = 0; neighbor_node < n; ++neighbor_node) {
            // 1. 자기 자신(current_node == neighbor_node)이 아니고
            // 2. 연결되어 있고 (computers[current_node][neighbor_node] == 1)
            // 3. 아직 방문하지 않았다면 (!visited_nodes[neighbor_node])
            if (current_node != neighbor_node && computers[current_node][neighbor_node] == 1 && !visited_nodes[neighbor_node]) {
                q.push(neighbor_node);         // 큐에 추가
                visited_nodes[neighbor_node] = true; // 방문 처리
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int network_count = 0;
    vector<bool> visited_nodes(n, false); 
    
    // 모든 컴퓨터를 순회하며 아직 방문하지 않은 컴퓨터를 찾음
    for (int i = 0; i < n; ++i) {
        if (!visited_nodes[i]) {
            bfs(i, n, computers, visited_nodes);
            network_count++;
        }
    }
    
    return network_count;
}