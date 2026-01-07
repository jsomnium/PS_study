#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 진출 지점 기준으로 정렬하기 위한 비교 함수
bool cmp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    // 진출 지점(routes[i][1]) 기준으로 오름차순 정렬
    sort(routes.begin(), routes.end(), cmp);
    
    // 마지막으로 설치한 카메라 위치
    // (초기값은 범위 밖인 -30001로 설정하여 첫 차는 무조건 찍게 함)
    int camera = -30001; 
    
    for (int i = 0; i < routes.size(); i++) {
        // 현재 차량의 진입 지점이 마지막 설치된 카메라보다 뒤에 있다면
        // (즉, 기존 카메라로는 이 차를 커버 못 함)
        if (camera < routes[i][0]) {
            answer++; // 카메라 한 대 추가
            camera = routes[i][1]; // 이 차량이 나가는 끄트머리에 카메라 설치 (최대한 뒤에 설치해야 이득)
        }
    }
    
    return answer;
}
