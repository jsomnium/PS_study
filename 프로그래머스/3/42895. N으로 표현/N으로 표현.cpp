#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;
    vector<set<int>> dp(9);
    
    // 5, 55 와 같은 연산 없는 숫자 구하기
    int originalNum = N;
    for (int i = 2; i <= 8; i++){
        originalNum = originalNum * 10 + N;
        dp[i].insert(originalNum);
    }
    
    // 시작점
    dp[1].insert(N);
    
    // dp 점화식 연산
    for (int i = 2; i <= 8; i++){
        for (int j = 1; j < i; j++){
            for (int a : dp[i-j]){
                for (int b : dp[j]){
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0 && a % b == 0)
                        dp[i].insert(a / b);
                }
            }
        }
        
        // 목표 숫자를 찾으면 바로 return
        if (dp[i].count(number)) return i;
    }
    
    // 못 찾을 시 -1
    return -1;
}