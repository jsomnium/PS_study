#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#include <iostream>

using namespace std;

// 진열된 모든 종류의 보석을 적어도 1개 이상 포함하는 가장 짧은 구간을 찾아서 구매하기
// 풀이 방식: 슬라이딩 윈도우
vector<int> solution(vector<string> gems) {
    set<string> gemSet(gems.begin(), gems.end());
    int total = gemSet.size();
    
    
    unordered_map<string, int> window;
    int left = 0;
    int ansLeft = 0, ansRight = gems.size() - 1;
    
    for (int right = 0; right < gems.size(); right++) {
        // right 보석을 윈도우에 추가
        window[gems[right]]++;
        
        // 윈도우에 모든 종류가 담겼으면?
        while (window.size() == total) {
            // 현재 구간이 더 짧으면 정답 갱신
            if (ansRight - ansLeft > right - left) {
                ansLeft = left; ansRight = right;
            }
            
            // left 보석을 윈도우에서 제거
            window[gems[left]]--;
            if (window[gems[left]] == 0) window.erase(gems[left]);
            left++;
        }
    }
    
    return {ansLeft + 1, ansRight + 1};
}