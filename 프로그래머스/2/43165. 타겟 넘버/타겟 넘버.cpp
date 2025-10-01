#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void dfs (int result, vector<int> numbers, int target, int index){
    if (index == numbers.size()){
        if (result == target) {
            cnt++;
        }
        return;
    }
    
    dfs(result + numbers[index], numbers, target, index + 1);
    dfs(result - numbers[index], numbers, target, index + 1);
}

int solution(vector<int> numbers, int target) {
    dfs(0, numbers, target, 0);
    
    return cnt;
}