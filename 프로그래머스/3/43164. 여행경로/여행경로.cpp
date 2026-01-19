#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// <출발 공항, {<도착 공항, 사용 여부>}>
map<string, vector<pair<string, bool>>> adj;
int totalTickets = 0;

bool dfs(string airport, vector<string>& answer) {
    answer.push_back(airport);
    if (answer.size() == totalTickets + 1) return true;

    for (auto& dest_pair : adj[airport]) {
        string next_airport = dest_pair.first;
        bool& is_used = dest_pair.second;

        if (is_used == false) {
            // 아직 사용하지 않은 티켓이라면
            is_used = true;
            
            if (dfs(next_airport, answer)) return true;

            // 백트래킹: 위 dfs 호출이 false를 반환했다 = next_airport로 간 것은 막다른 길.
            
            // 선택 취소
            is_used = false;
            answer.pop_back();
        }
    }
    
    return false;
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    totalTickets = tickets.size();
    
    for (auto ticket : tickets) adj[ticket[0]].push_back(make_pair(ticket[1], false));
    
    for (auto& a : adj) sort(a.second.begin(), a.second.end());
    
    dfs("ICN", answer);
    
    return answer;
}