#include <string>
#include <vector>

using namespace std;

void DFS(int& count, int targetCount, int target, int index, int number, vector<int> numbers){
    if (index == targetCount){
        if (number == target) count++;
        
        return;
    }
    
    DFS(count, targetCount, target, index + 1, number + numbers[index], numbers);
    DFS(count, targetCount, target, index + 1, number - numbers[index], numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int targetCount = numbers.size();
    
    DFS(answer, targetCount, target, 0, 0, numbers);
    
    return answer;
}