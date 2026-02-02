#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> carA, vector<int> carB){
    return carA[1] < carB[1];
}

int solution(vector<vector<int>> routes) {
    // routes[i][0] : i번째 차량이 고속도로에 진입한 지점
    // routes[i][1] : i번째 차량이 고속도로에서 나간 지점
    
    int answer = 0; // 카메라의 갯수
    int camera = -30001; // 카메라의 위치
    
    // 진입 시점이 작은 것 부터 정렬
    sort(routes.begin(), routes.end(), cmp);
    
    for (auto r : routes){
        if (r[0] > camera){
            answer++;
            camera = r[1];
        }
    }
    
    return answer;
}