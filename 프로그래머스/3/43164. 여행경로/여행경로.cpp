#include <string>
#include <vector>
#include <algorithm>
#include <map> // 맵 헤더 추가

using namespace std;

int totalTickets = 0;

bool dfs(string current, map<string, vector<pair<string, bool>>>& adj, vector<string>& answer) {
    answer.push_back(current);

    if (answer.size() == totalTickets + 1) return true;

    for (auto& ticket : adj[current]) {
        string nextAirport = ticket.first;
        bool& isUsed = ticket.second;

        if (isUsed) continue;

        isUsed = true;
        if (dfs(nextAirport, adj, answer)) return true;

        // 백트래킹
        isUsed = false;
        answer.pop_back();
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string, vector<pair<string, bool>>> adj; // 꺾쇠괄호 사용
    totalTickets = tickets.size();

    for (auto& t : tickets) {
        adj[t[0]].push_back({t[1], false});
    }

    // 알파벳 순서가 앞서는 경로를 찾기 위해 정렬
    for (auto& pair : adj) {
        sort(pair.second.begin(), pair.second.end());
    }

    dfs("ICN", adj, answer);
    return answer;
}