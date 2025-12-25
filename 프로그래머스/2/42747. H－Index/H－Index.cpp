#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0; // 반드시 0으로 초기화
    
    // 내림차순 정렬
    sort(citations.begin(), citations.end(), greater<int>());
    
    for (int i = 0; i < citations.size(); i++) {
        // [중요] 인용횟수(citations[i])가 현재 등수(i + 1)보다 크거나 같아야 함
        if (citations[i] >= i + 1) {
            answer = i + 1; // 현재 등수를 H-Index 후보로 저장
        } else {
            break; 
        }
    }
    
    return answer;
}