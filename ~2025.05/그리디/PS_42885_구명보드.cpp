#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, MinWeightIdx = 0;
    sort(people.begin(), people.end()); // 오름차순 정렬

    while(people.size() > MinWeightIdx){
        int MaxWeight = people.back(); people.pop_back();
        // 최댓값(vector.back)부터 태우고,
        // 최솟값(people[MinWeightIdx])도 같이 태울 수 있는 지 확인

        if(people[MinWeightIdx] + MaxWeight <= limit){
            // 같이 탑승 가능하다면 MinWeightIdx번째 사람도 같이 탑승
            answer++; MinWeightIdx++;
        }
        else answer++; // 같이 탑승 불가능하다면 보트 개수만 증가
    }

    return answer;
}