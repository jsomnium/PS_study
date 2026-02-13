#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    sort(P.begin(), P.end());
    int current_sum = 0; // 현재 사람이 기다린 시간
    int total_sum = 0;   // 모든 사람이 기다린 시간의 총합

    // 루프로 해결
    for (int i = 0; i < N; i++) {
        current_sum += P[i];   // 이전 사람들의 시간 + 내 시간
        total_sum += current_sum; // 총합에 누적
    }

    cout << total_sum;

    return 0;
}