#include <string>
#include <vector>

using namespace std;

void dfs(int index, vector<int> numbers, int& answer, int target, int total){
    if (index == numbers.size()){
        if (total == target) answer++;
        return;
    }
    
    dfs(index + 1, numbers, answer, target, total + numbers[index]);
    dfs(index + 1, numbers, answer, target, total - numbers[index]);
}

// 타겟 넘버
int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0, numbers, answer, target, 0);
    
    return answer;
}