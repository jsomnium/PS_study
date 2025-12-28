#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 가장 무거운 사람먼저 채우고 남는 무게를 가장 작은 사람으로 메꾼다
int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end(), greater<int>()); // 내림차순
    int highIdx = 0; // 가장 무거운 사람의 인덱스
    int lowIdx = people.size() - 1; // 가장 가벼운 사람의 인덱스
    int answer = 0; // 보트의 개수
    
    while (highIdx <= lowIdx){
        if (highIdx < lowIdx && people[highIdx] + people[lowIdx] <= limit){
            lowIdx--;
        }
        
        highIdx++;
        answer++;
    }
    
    return answer;
}
