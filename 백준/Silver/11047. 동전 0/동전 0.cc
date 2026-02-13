#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> coins(N);
    for (int i = 0; i < N; i++) cin >> coins[i];

    int answer = 0;

    // 큰 동전부터 확인하기 위해 뒤에서부터 반복문 수행
    for (int i = N - 1; i >= 0; i--) {
        if (K == 0) break; // 목표 금액을 다 채웠으면 종료

        if (coins[i] <= K) {
            // 현재 동전으로 만들 수 있는 최대 개수를 한 번에 계산
            answer += (K / coins[i]);
            // 남은 금액 갱신
            K %= coins[i];
        }
    }

    cout << answer;
    return 0;
}