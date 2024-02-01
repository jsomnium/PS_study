#include <vector>
using namespace std;

// 전역변수 answer
int answer = 0;

void DFS(vector<int> numbers, int target, int sum, int index){
    // 탐색 종료
    if (index == numbers.size()){
        if (sum == target) answer++;
        // 해당 경우 타겟 넘버를 만들었다면 answer 증가
        return;
    }
    // 탐색 (인덱스를 더하는/빼는 경우)
    DFS(numbers, target, sum + numbers[index], index + 1);
    DFS(numbers, target, sum - numbers[index], index + 1);
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, target, 0, 0);

    return answer;
}