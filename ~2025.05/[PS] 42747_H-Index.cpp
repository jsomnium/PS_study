#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>()); // 내림차순 정렬
    
    for(int i = 0; i < citations.size(); i++){
        if (citations[i] >= i + 1){
            answer = i + 1;
            // i + 1은 citations[i] 이상인 값의 개수이다.
        } else break;
    }
    
    return answer;
}
