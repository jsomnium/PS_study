#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp (vector<int> targetA, vector<int> targetB){
    return targetA[1] < targetB[1];
}

// (s, e) 범위가 주어졌을 때, s와 e는 제외하고
// 최소 개수를 사용해서 미사일 요격하기
// 실수 좌표에서도 발사 가능하다??

// 겹치는 구간이 주어졌을 때, 최소 갯수를 사용해서 공통 부분 빼기??
// 지난번에 풀었던 단속카메라와 비슷하게 풀면 될듯
int solution(vector<vector<int>> targets) {
    int answer = 0; // 미사일 개수
    int missile; // 현재 미사일의 위치
    
    sort(targets.begin(), targets.end(), cmp);
    
    // 가장 먼저, 미사일을 현재 타겟의 끝 부분에 위치시킨다
    // 다음번 미사일의 시작 지점이 끝나는 지점 미만이라면 같이 카운트
    // 다음번 미사일의 시작 지점이 끝나는 지점 이상이라면 anwer++;
    
    for (int i = 0; i < targets.size(); i++){
        missile = targets[i][1];
        
        while (i + 1 < targets.size() && targets[i + 1][0] < missile){
            i++;
        }
        
        answer++;
    }
    
    return answer;
}