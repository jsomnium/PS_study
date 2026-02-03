#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(int N, int number) {
    vector<set<int>> DP(9);
    DP[1].insert(N);
    // DP[i] = N을 i회 사용해서 만들 수 있는 수들의 배열
    // 즉, DP[1] = { N }
    // DP[2] = { 'NN', DP[1](연산)DP[1] }
    // DP[3] = { 'NNN', DP[1](연산)DP[2], DP[2](연산)DP[2] }
    
    if (N == number) return 1;
    
    int origin_number = N;
    for (int i = 2; i < 9; ++i){
        origin_number = origin_number * 10 + N;
        DP[i].insert(origin_number);
    }
    
    for (int i = 2; i < 9; ++i){
        for (int j = 1; j < i; ++j){
            for (int a : DP[i - j]){
                for (int b : DP[j]){
                    DP[i].insert(a + b);
                    DP[i].insert(a - b);
                    DP[i].insert(a * b);
                    if (b != 0 && a % b == 0) DP[i].insert(a / b);
                }
            }
        }
        if (DP[i].count(number)) return i;
    }
    
    return -1;
}