#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // 1. 정렬
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    // 2. 정렬해서 비교
    for (int i = 0; i < participant.size(); i++){
        if (i == participant.size() - 1){
            // 정렬 기준 마지막 사람이 completition에 없는 경우에는 배열 길이 때문에 체크 못하므로 따로 if문으로 빼주기
            answer = participant[i];
            break;
        }
        else if (participant[i] != completion[i]){
            // 비교한 값이 없다면 정답
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}