#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int size = name.size();
    
    // 1. 상하 조작
    for (char c : name) {
        answer += min(c - 'A', 'Z' - c + 1);
    }
    
    // 2. 좌우 조작
    int move = size - 1; // 기본 우측 이동 시의 최대 이동 횟수
    for (int i = 0; i < size; ++i){
        int next = i + 1; // 다음에 방문할 인덱스
        
        // 다음 목표 찾기
        // A라면 상하 조작이 필요 없으므로 건너뛰기
        while (next < size && name[next] == 'A')
            ++next;
        
        // 오른쪽으로 갔다가 되돌아오는 경우
        // 오른쪽 i + 왼쪽 i (되돌아오기) + 오른쪽 (n - next)
        int path1 = 2 * i + (size - next);
        
        // 왼쪽으로 먼저 가는 경우
        // 왼쪽 (n - next) + 오른쪽 (n - next) + 오른쪽 (i) 
        int path2 = i + 2 * (size - next);
        
        move = min ({move, path1, path2});
    }
    
    return answer + move;
}