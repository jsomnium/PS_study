#include <string>
#include <vector>

using namespace std;

int count = 0;

void dfs(vector<int> numbers, int index, int sum, int target){
    if (numbers.size() == index){
        if (sum == target) count++;
        return;
    }
    
    dfs(numbers, index + 1, sum + numbers[index], target);
    dfs(numbers, index + 1, sum - numbers[index], target);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, 0, 0, target);
    
    return count;
}