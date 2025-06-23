#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    // 우선순위 큐 오름차순 정렬
    // 가장 작은 수(top)가 K 이상이 되는 최소 횟수 구하기

    while (pq.top() < K && pq.size() > 1){
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        pq.push(first + 2 * second);
        answer++;
    }

    if (pq.size() == 1 && pq.top() < K) return -1;
    // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1
    
    return answer;
}
