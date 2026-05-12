#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;

// 동일한 유저에 대한 신고 횟수는 1회로 처리
// k번 이상 신고된 유저는 게시판 이용이 정지
// 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    unordered_map<string, int> userMap; // {유저 이름, 유저 아이디}
    
    for (int index = 0; index < id_list.size(); ++index)
        userMap[id_list[index]] = index;
    
    unordered_map<int, set<int>> ReportMap; // {신고당한 유저 아이디, {신고한 유저 아이디 배열}}
    
    for (auto r : report){
        stringstream ss(r);
        
        string userId, reportedId;
        ss >> userId >> reportedId;
        
        ReportMap[userMap[reportedId]].insert(userMap[userId]);
    }
    
    // reportMap 순회하면서
    // value vector의 size > k 이면 유저들에게 메일 전송
    
    for (auto& [reported, reporters] : ReportMap) {
        if (reporters.size() >= k) {
            for (auto user : reporters) {
                answer[user]++;
            }
        }
    }
    
    return answer;
}