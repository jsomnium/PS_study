#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    // N이 커질 것에 대비해 long long 사용, 인덱스 N까지 쓰려면 크기는 N+1
    vector<long long> F(N + 1, 1); 

    // 0! = 1, 1! = 1 이므로 2부터 계산
    for (int i = 2; i <= N; i++) {
        F[i] = F[i - 1] * i;
    }

    cout << F[N] << endl;
    return 0;
}