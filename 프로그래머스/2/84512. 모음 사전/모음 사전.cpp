#include <string>
#include <vector>
using namespace std;

string vowels = "AEIOU";
int answer = 0;
int order = 0;

// 사전 순서대로 단어를 하나씩 다 만들어보면서 순서를 센다
void dfs(string current, string& target) {
    if (current == target) {
        answer = order;
        return;
    }

    if (current.length() >= 5) return;

    for (int i = 0; i < 5; i++) {
        order++;
        dfs(current + vowels[i], target);
        if (answer != 0) return; // 찾았으면 바로 종료
    }
}

int solution(string word) {
    dfs("", word);
    return answer;
}
