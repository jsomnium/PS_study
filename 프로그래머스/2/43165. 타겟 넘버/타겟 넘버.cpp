#include <string>
#include <vector>

using namespace std;

void dfs(int index, int& target, int& count, int sum, vector<int> numbers){
    if (index == numbers.size()){
        if (sum == target) count++;
        return;
    }
    
    dfs(index + 1, target, count, sum + numbers[index], numbers);
    dfs(index + 1, target, count, sum - numbers[index], numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0, target, answer, 0, numbers);
    
    return answer;
}
