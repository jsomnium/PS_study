#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool isDiffOne(string a, string b){
    if (a.length() != b.length()) return false;
    
    int diff = 0;
    
    for (int i = 0; i < a.length(); i++){
        if (a[i] != b[i]) diff++;
    }
    
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<int, string>> q; // 변환 횟수, 현재 단어
    vector<bool> visited(words.size(), false); // words 배열의 인덱스로 방문 체크
    
    q.push(make_pair(0, begin)); // 시작점을 큐에 넣어주기
    
    while (!q.empty()){
        int changeCnt = q.front().first;
        string prevWord = q.front().second;
        
        q.pop();
        
        if (prevWord == target){
            answer = changeCnt;
            break;
        }
        
        for (int i = 0; i < words.size(); i++){
            if (!visited[i] && isDiffOne(prevWord, words[i])){
                // 방문한 적이 없고, 한 알파벳만 다르다면
                q.push(make_pair(changeCnt + 1, words[i]));
                visited[i] = true;
            }
        }
    }
    
    return answer;
}