#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> workQueue;
    
    // 큐에 작업의 남은 퍼센트(100-progress)를 저장
    for (int i = 0; i < progresses.size(); i++) {
        workQueue.push((100 - progresses[i] + speeds[i] - 1) / speeds[i]); 
        // (100 - 현재 진도) / 속도 → 필요한 날짜 계산
        // + speeds[i] - 1 을 하는 이유: 나누기 연산에서 올림 효과를 얻기 위해
    }

    while (!workQueue.empty()) {
        int first = workQueue.front(); // 맨 앞 작업의 완료 예상 날짜
        workQueue.pop();
        int count = 1; // 배포되는 기능 개수

        // 뒤의 작업들도 함께 배포될 수 있는지 확인
        while (!workQueue.empty() && workQueue.front() <= first) {
            workQueue.pop();
            count++;
        }

        answer.push_back(count); // 한 번에 배포된 기능 개수 추가
    }
    
    return answer;
}
