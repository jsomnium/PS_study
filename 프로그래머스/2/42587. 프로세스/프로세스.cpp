#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> Process;
    queue<int> Location;
    priority_queue<int> Priority;
    
    // 우선순위대로 큐에 넣기
    for (int index = 0; index < priorities.size(); index++){
        Process.push(priorities[index]);
        Location.push(index);
        Priority.push(priorities[index]);
    }
    
    // priorities[location]의 수가 몇 번째에 pop() 되는지 알아야 한다
    // 인덱스를 쫓는 큐를 하나 더 만들어서, 지금 pop하는 인덱스가 location이면
    // 이 때의 answer가 정답
    while(!Process.empty()){
        int process_front = Process.front(); Process.pop();
        int process_index = Location.front(); Location.pop();
        int priority_front = Priority.top(); Priority.pop();
        
        cout << "process_front: " << process_front << endl;
        cout << "process_index: " << process_index << endl;
        cout << "priority_front: " << priority_front << endl;
        
        // 현재 큐의 front가 pop 가능한지 체크
        // 제일 큰 수를 체크하는데.. 그니까 그 다음 나가야 할 수를 체크하는거임.
        
        if (process_front < priority_front){
            // pop 불가능, 다시 큐에 넣기
            Process.push(process_front);
            Location.push(process_index);
            Priority.push(priority_front);
            cout << "pop 불가능" << endl;
        } else {
            // pop 가능, pop 횟수 증가
            answer++;
            cout << "pop 가능, answer: " << answer;
            if (process_index == location){
                // 만약 현재 pop한 것이 location이라면 정답
                cout << "정답, answer: " << answer;
                return answer;
            }
        }
    }
    
    // [3, 9, 1, 4]
    // [9, 1, 4, 3]
    // [1, 4, 3]
    // [4, 3, 1]
    // [3, 1]
    // [1]
    return answer;
}