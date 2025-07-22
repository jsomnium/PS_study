#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 1) 도난+여벌 겹치는 학생 제거
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    vector<int> realLost;
    vector<bool> used(reserve.size(), false);
    
    // 먼저, 겹치는 학생 찾기
    for (int x : lost) {
        bool kept = false;
        for (int j = 0; j < reserve.size(); ++j) {
            if (!used[j] && reserve[j] == x) {
                // 이 학생은 도난당했지만 여벌도 있음 → 남에게 빌려줄 수 없음
                used[j] = true;
                kept = true;
                break;
            }
        }
        if (!kept) {
            realLost.push_back(x);
        }
    }
    
    // 2) 실제로 옷이 필요한 학생 목록(realLost)과
    // 여벌 옷을 줄 수 있는 학생(reserve 중 used==false) 정리
    vector<int> realReserve;
    for (int j = 0; j < reserve.size(); ++j) {
        if (!used[j]) realReserve.push_back(reserve[j]);
    }
    
    sort(realLost.begin(), realLost.end());
    sort(realReserve.begin(), realReserve.end());
    
    // 3) 그리디로 빌려주기
    for (int r : realReserve) {
        for (auto it = realLost.begin(); it != realLost.end(); ++it) {
            if (abs(r - *it) == 1) {
                realLost.erase(it);
                break;
            }
        }
    }
    
    // 4) 체육복 없는 학생 수 = realLost.size()
    return n - (int)realLost.size();
}
