#include <string>
#include <vector>
using namespace std;

string vowels = "AEIOU";
int answer = 0; // 정답
int count = 0; // 몇 번째 단어인지 횟수 계산

void dfs(string cur_str, string word){
    if (cur_str == word){
        answer = count;
        return;
    }

    if (cur_str.length() >= 5) return;
    
    for (int i = 0; i < 5; i++){
        count++;
        dfs(cur_str + vowels[i], word);
        if (answer != 0) return;
        // answer가 0이 아니라면 정답을 찾은 것이므로 dfs 탐색 종료
    }
}

int solution(string word) {
    dfs("", word);
    return answer;
}
