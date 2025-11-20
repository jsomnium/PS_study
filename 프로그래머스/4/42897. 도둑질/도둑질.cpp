#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dp[1000000];

int solution(vector<int> money) {
    int answer;
    int len = money.size();
    
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);
    for(int i=2; i<len-1; i++){
        dp[i] = max(dp[i-2]+money[i], dp[i-1]);
    }
    
    answer = dp[len-2];
    
    dp[0] = 0;
    dp[1] = money[1];
    for(int i=2; i<len; i++){
        dp[i] = max(dp[i-2]+money[i], dp[i-1]);
    }
    
    answer = max(answer, dp[len-1]);
    return answer;
}