#include <string>
#include <vector>
#include <queue>
 
using namespace std;
 
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int next_truck = 0;     // 대기 트럭 중 맨 앞의 트럭의 인덱스
    int weight_sum = 0;     // 다리 위에 있는 트럭의 무게 합
    queue<int> on_bridge;   // 다리 위에 있는 트럭
 
    // 다리 위에 있을 수 있는 트럭의 수 만큼 미리 넣어둠
    for (int i = 0; i < bridge_length; i++)
        on_bridge.push(0);
 
    while (!on_bridge.empty()) {
        answer++;
        weight_sum -= on_bridge.front();
        on_bridge.pop();
 
        // 대기 트럭이 있는 경우
        if (next_truck < truck_weights.size()) {
            // 다리 무게 조건 만족시, 트럭 push
            if (weight_sum + truck_weights[next_truck] <= weight) {
                weight_sum += truck_weights[next_truck];
                on_bridge.push(truck_weights[next_truck]);
                next_truck++;
            }
            // 만족 X시, 0 push
            else {
                on_bridge.push(0);
            }
        }
    }
 
    return answer;
}