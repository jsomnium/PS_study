#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int convertTimeToInt(string time){
    int hours = 0; int times = 1;
    for (int i = 1; i >= 0; i--){
        hours += times * (time[i] - '0');
        times *= 10;
    }
    
    int minutes = 0; times = 1;
    for (int i = 4; i >= 3; i--){
        minutes += times * (time[i] - '0');
        times *= 10;
    }
    
    int seconds = 0; times = 1;
    for (int i = 7; i >= 6; i--){
        seconds += times * (time[i] - '0');
        times *= 10;
    }
    
    return hours * 60 * 60 + minutes * 60 + seconds; 
}

// 풀이 알고리즘: 슬라이딩 윈도우
// 시청자들이 가장 많이 보는 구간에 공익광고를 삽입하려고 한다
// 공익광고가 들어갈 시작 시각을 구해서 return하기
// 여러 개라면, 그 중에서 가장 빠른 시각을 return한다
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int advPlayTimeAns = 0; // 광고 시작 시간 정답
    int advPlayCountAns = 0; // 겹치는 광고 수 정답
    
    int adv_time_int = convertTimeToInt(adv_time);
    int play_time_int = convertTimeToInt(play_time);
    
    // 시작 시간 기준 오름차순 정렬
    sort(logs.begin(), logs.end());
    
    // 동영상 재생 시간 변환
    vector<pair<int, int>> logs_int; // {시작 시간, 종료 시간}
    for (auto l : logs) {
        int startTime = convertTimeToInt(l.substr(0, 8));
        int endTime = convertTimeToInt(l.substr(9, 17));
        logs_int.push_back({startTime, endTime});
    }
    
    /*
    diff[] 배열에 겹치는 동영상의 개수 구하기
    구할 때는 누적합을 사용한다 -> 그냥 구하면 시간초과, 누적합은 O(N)
    이후 슬라이딩 윈도우로 가장 큰 값이 있는 곳을 찾는다
    */
    
    // 누적합
    vector<int> diff(play_time_int + 1, 0);
    for (auto l : logs_int){
        diff[l.first] += 1; diff[l.second] -= 1;
    }
    
    for (int i = 1; i < diff.size(); i++)
        diff[i] += diff[i - 1];
    
    // 슬라이딩 윈도우
    // 누적합으로 한번 더 구한다
    // 그다음 R L 슬라이딩 윈도우 하면 됨
    
    vector<long long> sum(play_time_int + 1, 0);
    for (int i = 1; i <= play_time_int; i++)
        sum[i] = sum[i-1] + diff[i-1];
    
    long long maxSum = sum[adv_time_int] - sum[0];
    int answerInt = 0;

    for (int i = 1; i + adv_time_int <= play_time_int; i++){
        long long cur = sum[i + adv_time_int] - sum[i];
        if (cur > maxSum){
            maxSum = cur;
            answerInt = i;
        }
    }
    
    // 정답 문자열 변환
    int h = answerInt / 3600;
    int m = (answerInt % 3600) / 60;
    int s = answerInt % 60;
    
    auto pad = [](int n) -> string {
        return (n < 10 ? "0" : "") + to_string(n);
    };

    answer = pad(h) + ":" + pad(m) + ":" + pad(s);
    
    return answer;
}