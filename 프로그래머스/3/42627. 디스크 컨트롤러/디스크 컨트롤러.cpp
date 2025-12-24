#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// 일반 배열 정렬에서는 true를 반환 시, 왼쪽이 오른쪽보다 앞에 온다
// 구조체에서는 true를 반환 시, 오른쪽이 왼쪽보다 우선순위가 높다
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq; // 대기큐
    sort(jobs.begin(), jobs.end()); // 요청 시각 우선으로 정렬
    
    int CUR_TIME = 0; // 현재 시각
    int RETURN_TIME_SUM = 0; // 반환 시간 총합
    int DISK_INDEX = 0;
    int NUM_OF_JOBS = jobs.size();
    
    while(DISK_INDEX < NUM_OF_JOBS || !pq.empty()){
        cout << "[" << CUR_TIME << "초 작업 시작]" << endl;
        
        // 대기큐에 작업 넣기
        while(DISK_INDEX < NUM_OF_JOBS && CUR_TIME >= jobs[DISK_INDEX][0]){
            cout << DISK_INDEX << "번째 작업은, 요청 시각보다 현재 시간이 더 크거나 같으므로 대기큐에 넣음" << endl;
            pq.push(jobs[DISK_INDEX]);
            DISK_INDEX++;
        }
        
        // 대기큐에서 디스크 컨트롤러로 작업 수행하기
        if (pq.empty()) {
            CUR_TIME = jobs[DISK_INDEX][0];
        } else {
            vector<int> job = pq.top();
            pq.pop();
            
            // 시간 흐름 업데이트
            CUR_TIME += job[1];
            // 요청에서 종료까지 걸린 시간 더하기
            RETURN_TIME_SUM += CUR_TIME - job[0];
        }
    }
    
    return RETURN_TIME_SUM / NUM_OF_JOBS;
}