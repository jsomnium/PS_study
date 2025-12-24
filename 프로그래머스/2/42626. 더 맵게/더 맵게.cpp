#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    
    for (auto s : scoville) pq.push(s);
    
    while (pq.top() < K && pq.size() > 1){
        ans++;
        int cur_scoville = pq.top(); pq.pop();
        int next_scoville = pq.top(); pq.pop();
        int mix_scoville = cur_scoville + (2 * next_scoville);
        pq.push(mix_scoville);
    }
    
    if (pq.size() == 1 && pq.top() < K) return -1;
    
    return ans;
}