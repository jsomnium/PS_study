#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b){
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

// 1931번 회의실 배정: 최대 사용할 수 있는 회의의 최대 개수 출력하기
// => 회의실이 한 개 있다. 회의를 최대한 많이 할 수 있도록 해서 배치해보기!!
int main(){
    // 회의 수 입력
    int N;
    cin >> N;
    
    // 회의 시작, 종료 시간 입력
    vector<vector<int>> MeetingTime(N, vector<int>(2, 0));
    for (int i = 0; i < N; i++) cin >> MeetingTime[i][0] >> MeetingTime[i][1];

    // 종료 시간 기준으로 오름차순 정렬
    sort(MeetingTime.begin(), MeetingTime.end(), cmp);
    
    // 종료 시간이 작은 것 부터 사용
    int answer = 0;
    int time = 0;
    for (int i = 0; i < N; i++){
        if (MeetingTime[i][0] >= time){
            answer++;
            time = MeetingTime[i][1];
        }
    }
    
    cout << answer;
    return 0;
}