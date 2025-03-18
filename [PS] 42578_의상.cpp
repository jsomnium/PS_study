#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> m;

    for(auto p:clothes){
        m[p[1]]++;
        // clothes는 {의상명, 의상 종류} 이므로
        // p[1]을 해시맵 m의 키값으로 설정해주어야 한다.
        // 의상의 종류를 계속 카운트 해야하므로, ++ 로 설정.
    }

    for(auto p:m){
        answer *= (p.second+=1);
        // p는 {의상 종류, 의상 개수} 이므로
        // p.second 를 가져와서 +1을 한 뒤, 전부 곱해주어야 한다.
    }

    return answer-1;
    // 전부 입지 않는 경우의 수 1가지를 빼면 정답이다.
}
