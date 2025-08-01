#include <string>
#include <vector>

using namespace std;

bool isVisited[201];

void DFS(int cur, int n, vector<vector<int>> com){
    isVisited[cur] = true;
    
    for (int i = 0; i < n; i++){
        if(!isVisited[i] && com[cur][i] == 1){
            DFS(i, n, com);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    // 방문 체크만 잘 세면 되는 문제
    for (int i = 0; i < n; i++){
        if (!isVisited[i]){
            DFS(i, n, computers);
            answer++;
        }
    }
    
    return answer;
}