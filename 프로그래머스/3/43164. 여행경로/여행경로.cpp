#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, vector<pair<string, bool>>> adj;
int totalTickets = 0;

bool dfs(string airport, vector<string>& answer){
    answer.push_back(airport);
    
    if (answer.size() == totalTickets + 1) return true;
    
    for (auto& vec : adj[airport]){
        string dest = vec.first;
        bool& isUsed = vec.second;
        
        if (isUsed == false){
            isUsed = true;
            
            if (dfs(dest, answer)) return true;
            
            isUsed = false;
            answer.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    totalTickets = tickets.size();
    
    for (auto t : tickets) adj[t[0]].push_back(make_pair(t[1], false));
    
    for (auto& a : adj) sort(a.second.begin(), a.second.end());
    
    dfs("ICN", answer);
    
    return answer;
}