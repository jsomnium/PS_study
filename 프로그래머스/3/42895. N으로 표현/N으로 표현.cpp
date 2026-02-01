#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(int N, int number) {
    vector <set<int>> dp(9);
    dp[1].insert(N);
    
    // 같은 수 일 경우 바로 return하기
    if (N == number) return 1; 
    
    // 2 이상부터는 N 사용 횟수 카운트로 dp식 세워서 목표 number 찾기
    
    // 5, 55, 555, 5555 와 같은 연속 숫자 포함
    int originalNum = N;
    for (int i = 2; i <= 8; i++){
        originalNum = 10 * originalNum + N;
        dp[i].insert(originalNum);
    }
    
    // 모든 연산 후 숫자 찾기
    for (int i = 2; i <= 8; i++){
        for (int j = 1; j < i; j++){
            for (int a : dp[i - j]){
                for (int b : dp [j]){
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0 && a % b == 0) dp[i].insert(a / b);
                }
            }
        }
    if(dp[i].count(number)) return i; // 최솟값을 찾는 것이므로 바로 return
    }
    
    return -1;
}