// 문제: 피보나치 수열
// 유형: 다이나믹 프로그래밍
// 난이도: 브론즈2

// 재귀함수로 풀이하면 시간 초과가 뜨므로 DP를 이용한다.

#include <iostream>
using namespace std;

// 한 번 계산된 결과를 메모하기 위한 배열
int memo[100] = {0, };

int fibo(int x){
    if (x<=1) return x; // 1,0 일때 1 반환
    if (memo[x] != 0) return memo[x]; // 계산한 적 있다면 그대로 반환
    memo[x] = fibo(x-1) + fibo(x-2);
    return memo[x];
}

int main(){
    int n;
    cin >> n;
    cout << fibo(n) << '\n';
    return 0;
}