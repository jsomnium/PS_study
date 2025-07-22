#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 비교를 위한 오름차순 정렬
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    // 도난, 여벌 중복 학생 제거
    // 중복 학생들을 제거한 새로운 newLost, newReserve 배열을 만든다
    vector<int> newLost;
    vector<int> newReserve;
    vector<bool> used(reserve.size(), false);
    
    // newLost 배열 만들기
    for (int x : lost){
        bool isDuplicated = false;
        
        // 중복 찾기
        for (int i = 0; i < reserve.size(); ++i){
            if (!used[i] && reserve[i] == x){
                isDuplicated = true; // 중복으로 처리
                used[i] = true; // 입은 것으로 처리
                break;
            }
        }
        
        // 중복을 제외한 새로운 배열 추가
        if (!isDuplicated)
            newLost.push_back(x);
    }
    
    // newReserve 배열 만들기
    for (int j = 0; j < reserve.size(); ++j)
        if (!used[j]) newReserve.push_back(reserve[j]);
    
    // 규칙을 위한 오름차순 정렬
    sort(newLost.begin(), newLost.end());
    sort(newReserve.begin(), newReserve.end());
    
    // 옷 빌려주기
    for (int r : newReserve){
        for (auto it = newLost.begin(); it != newLost.end(); ++it){
            if (abs(r - *it) == 1){
                newLost.erase(it);
                break;
            }
        }
    }
    
    return n - (int)newLost.size();
}