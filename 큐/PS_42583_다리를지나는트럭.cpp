#include <string>
#include <queue>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int Answer = 0; // 경과 시간
    queue<int> WaitingTruck;
    queue<pair<int,int>> AcrossingTruck; // 다리를 지나는 중인 트럭
    int onBridgeWeight = 0; // 다리를 지나는 중인 트럭의 무게 합
    int onBridgeCount = 0; // 다리를 지나는 중인 트럭의 개수

    for (int i = 0; i < truck_weights.size(); i++){
        WaitingTruck.push(truck_weights[i]);
    }

    do {
        Answer++;
        if (!AcrossingTruck.empty() && AcrossingTruck.front().first >= bridge_length){
            onBridgeWeight -= AcrossingTruck.front().second;
            AcrossingTruck.pop();
        }
        if (onBridgeCount < bridge_length && onBridgeWeight + WaitingTruck.front() <= weight)
        {
            onBridgeCount++;
            onBridgeWeight += WaitingTruck.front();
            WaitingTruck.pop();
            AcrossingTruck.front().first += 1;
            AcrossingTruck.push(make_pair(0,WaitingTruck.front()));
        }
    } while (!AcrossingTruck.empty());

    return Answer;
}