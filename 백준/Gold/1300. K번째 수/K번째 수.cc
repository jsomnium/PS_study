#include <iostream>
#include <algorithm>

using namespace std;

/**
 * [핵심 아이디어]
 * 1. B[K] = X 라고 할 때, X보다 작거나 같은 수의 개수는 최소 K개 이상이다.
 * 2. 숫자 X가 커질수록, X보다 작거나 같은 수의 개수(cnt)는 늘어난다. (결정 문제/이분 탐색 가능)
 * 3. i행에서 X보다 작거나 같은 수의 개수는 min(X / i, N) 이다.
 */

int main() {
    // 입출력 속도 향상 (지수님이 아까 썼던 fastio)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K;
    cin >> N >> K;

    // 이분 탐색 범위 설정
    // low: 숫자의 최솟값 (1)
    // high: K번째 숫자는 아무리 커도 K를 넘을 수 없음 (high = K)
    long long low = 1;
    long long high = K; 
    long long ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2; // 우리가 지금 테스트해볼 "숫자"
        long long cnt = 0;               // mid보다 작거나 같은 숫자의 총 개수

        // 각 행(단)을 돌면서 mid보다 작거나 같은 숫자가 몇 개인지 합산
        for (int i = 1; i <= N; i++) {
            // i단에서 mid 이하의 개수는 mid / i 임. 
            // 단, 한 행의 최대 개수인 N을 넘을 수는 없음!
            cnt += min(mid / i, N);
        }

        if (cnt >= K) {
            // mid보다 작거나 같은 게 K개 이상이라면? 
            // "mid가 너무 큰가? 더 작은 숫자 중에도 답이 있나?" 확인
            ans = mid;         // 일단 정답 후보로 저장
            high = mid - 1;    // 왼쪽 범위를 탐색 (숫자를 줄임)
        } else {
            // mid보다 작거나 같은 게 K개보다 적다면? 
            // "숫자가 너무 작네! 더 키워야겠다."
            low = mid + 1;     // 오른쪽 범위를 탐색 (숫자를 키움)
        }
    }

    // 최종적으로 찾은 'cnt >= K를 만족하는 최소의 mid' 출력
    cout << ans << "\n";

    return 0;
}