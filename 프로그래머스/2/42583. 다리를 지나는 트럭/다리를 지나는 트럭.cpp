#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> Truck;
    queue<int> Bridge;
    int answer = 0;
    int bridge_weight = 0;
    
    for (auto t: truck_weights) Truck.push(t); // 대기큐
    for (int i = 0; i < bridge_length; i++) Bridge.push(0);
    
    while(!Truck.empty()){
        answer++;
        
        bridge_weight -= Bridge.front();
        Bridge.pop();
        
        // 현재 다리 무게 + 다음 트럭 무게 체크
        if (bridge_weight + Truck.front() <= weight){
            // 무게 여유가 있으면 트럭 진입
            Bridge.push(Truck.front());
            bridge_weight += Truck.front();
            Truck.pop();
        } else {
            // 여유가 없으면 0을 밀어넣음
            Bridge.push(0);
        }
    }
    
    // 마지막 트럭이 다리에 올라간 시점에서 루프가 끝남
    // 그 트럭이 다리를 완전히 건너려면 '다리 길이'만큼 시간이 더 필요함
    return answer + bridge_length;
}