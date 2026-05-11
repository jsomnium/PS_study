#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int toInt(string num){
    return 3600 * stoi(num.substr(0,2)) + 60 * stoi(num.substr(3,5)) + stoi(num.substr(6,8));
}

string toString(int num){
    int hour = num / 3600;
    int minute = (num % 3600) / 60;
    int second = num % 60;
    
    auto pad = [](int n) -> string {
        return (n < 10 ? "0" : "") + to_string(n);
    };
    
    return pad(hour) + ":" + pad(minute) + ":" + pad(second);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int advPlayTimeAns = 0;
    int advPlayCountAns = 0;
    
    int adv_time_int = toInt(adv_time);
    int play_time_int = toInt(play_time);
    
    sort(logs.begin(), logs.end());
    
    vector<pair<int, int>> logs_int;
    for (auto l : logs){
        int startT = toInt(l.substr(0,8));
        int endT = toInt(l.substr(9,17));
        logs_int.push_back({startT, endT});
    }
    
    // 누적합 적용
    vector<int> diff(play_time_int + 1, 0);
    for (auto l : logs_int){
        diff[l.first] += 1;
        diff[l.second] -= 1;
    }
    
    for (int i = 1; i < diff.size(); i++){
        diff[i] += diff[i - 1];
    }
    
    // 슬라이딩 윈도우
    vector<long long> sum(play_time_int + 1, 0);
    for (int i = 1; i <= play_time_int; i++)
        sum[i] += sum[i-1] + diff[i-1];
    
    long long maxSum = sum[adv_time_int] - sum[0];
    int answerInt = 0;
    
    for (int i = 1; i + adv_time_int <= play_time_int; i++){
        long long cur = sum[i + adv_time_int] - sum[i];
        if (cur > maxSum){
            maxSum = cur;
            answerInt = i;
        }
    }
    
    return toString(answerInt);
}