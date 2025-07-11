#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

vector<int> graph[101];  // 인접 리스트
bool visited[101];       // 방문 체크 배열

// DFS로 연결된 노드 수를 세는 함수
int dfs(int node) {
    visited[node] = true;
    int count = 1;

    for (int next : graph[node]) {
        if (!visited[next]) {
            count += dfs(next);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;  // 최대 차이값은 n이므로 초기값은 n

    for (int i = 0; i < wires.size(); i++) {
        // 1. 그래프 초기화
        for (int j = 1; j <= n; j++) {
            graph[j].clear();
        }

        // 2. i번째 전선을 끊고, 나머지로 그래프 구성
        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue;  // 이번 전선은 끊음
            int a = wires[j][0];
            int b = wires[j][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // 3. DFS 탐색을 통해 한 쪽의 송전탑 개수 구하기
        memset(visited, false, sizeof(visited));
        int group1 = dfs(1);             // 아무 노드부터 탐색
        int group2 = n - group1;         // 나머지 노드는 전체 - group1

        // 4. 두 그룹 차이의 최솟값 갱신
        answer = min(answer, abs(group1 - group2));
    }

    return answer;
}
