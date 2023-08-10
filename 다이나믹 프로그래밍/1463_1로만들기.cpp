// 문제: 1로 만들기
// 유형: 다이나믹 프로그래밍
// 난이도: 실버3

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int d[10000001];

    d[1] = 0;
    d[2] = 1;
    d[3] = 1;

    for ( int i = 4 ; i <= n ; i++ ){
        d[i] = d[i-1] + 1; // 1을 빼고 계산하는 경우는 +1을 해주면 된다
        if ( i % 2 == 0 ) // 2로 나누어 떨어지는 경우,
            d[i] = min(d[i], d[i/2] + 1); // 1을 빼고 계산하는 경우와 비교해서 작은 값을 넣는다
        if ( i % 3 == 0 ) // 3으로 나누어 떨어지는 경우,
            d[i] = min(d[i], d[i/3] + 1); // 1을 빼고 계산하는 경우와 비교해서 작은 값을 넣는다
    }

    cout << d[n] << endl;
    return 0;
}