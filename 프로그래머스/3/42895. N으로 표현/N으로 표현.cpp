#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;
    vector<set<int>> dp(9);
    
    dp[1].insert(N);
    
    // (55, 555 등) 미리 추가
    int concat = N;
    for (int i = 2; i <= 8; i++) {
        concat = concat * 10 + N;
        dp[i].insert(concat);
    }
    
    for (int i = 2; i <= 8; i++) {
        for (int j = 1; j < i; j++) {
            for (int a : dp[i-j]) {
                for (int b : dp[j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0 && a % b == 0)  // b로 나눴을 때 나머지 0일 때만
                        dp[i].insert(a / b);
                    if (a != 0 && b % a == 0)  // a로 나눌 수도 있으니
                        dp[i].insert(b / a);
                }
            }
        }
        
        if (dp[i].count(number)) return i;
    }
    
    return -1;
}