#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    
    for (auto p : participant){
        m[p]++;
    }
    
    for (auto c : completion){
        m[c]--;
    }
    
    for (auto pair : m){
        if (pair.second > 0) return pair.first;
    }
}