// 문제: 1, 2, 3 더하기
// 유형: 다이나믹 프로그래밍
// 난이도: 실버3

#include <iostream>
using namespace std;

int main(){
    int T, N; // 테스트 케이스의 개수, 정수 N
    int DP[11]; // 1~T 를 만들기 위한 방법의 수 저장

    cin >> T;

    DP[1] = 1; // 1
    DP[2] = 2; // 1 + 1, 2
    DP[3] = 4; // 1 + 1 + 1, 1 + 2, 2 + 1, 3

    for (int i = 4; i < 11; i++) // DP 값 미리 구하기
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];

    while (T--){
        cin >> N;
        cout << DP[N] << "\n";
    }

    return 0;
}