#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    // 내림차순 정렬에서 가장 작은 수가 K가 넘도록 하면, 모든 수가 K이상이다.
    // 우선순위 큐 정렬 기준을 오름차순(MinHeap)으로 정한다.
    // 가장 작은 수가 K를 넘을 때까지 연산하고, 횟수를 카운트해서 반환한다.
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.top() < K && pq.size() > 1){
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        pq.push(first + 2 * second);
        answer++;
    }

    // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1
    if (pq.size() == 1 && pq.top() < K) return -1;
    
    return answer;
}