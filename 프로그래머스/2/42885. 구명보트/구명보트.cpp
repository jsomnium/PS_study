#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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