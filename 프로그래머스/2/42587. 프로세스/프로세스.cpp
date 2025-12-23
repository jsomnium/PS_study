#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> Priorities; // 우선순위 저장 큐 (큰 수가 높은 우선순위)
    queue<int> Queue; // 대기큐
    
    for (int i = 0; i < priorities.size(); i++){
        Queue.push(i); // 대기큐에 넣기
        Priorities.push(priorities[i]); // 큰 수가 높은 우선순위를 가짐
    }
    
    // 대기큐가 빌 때 까지
    int answer = 0;
    while (!Queue.empty()){
        int frontIndex = Queue.front();
        Queue.pop();
        if (priorities[frontIndex] == Priorities.top()){
            // 지금 뽑은 프로세스가 우선순위가 가장 높은 큐일 때
            Priorities.pop();
            answer++;
            if (frontIndex == location) return answer;
        } else {
            // 더 높은 우선순위가 있을 때
            Queue.push(frontIndex);
        }
    }
}