#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;

    vector<long long> lan(K);
    long long max_len = 0;
    for (int i = 0; i < K; i++) {
        cin >> lan[i];
        if (lan[i] > max_len) max_len = lan[i];
    }

    long long low = 1;
    long long high = max_len;
    long long answer = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long cnt = 0;

        for (int i = 0; i < K; i++) {
            cnt += (lan[i] / mid);
        }

        if (cnt >= N) {
            // N개 이상 만들 수 있다면?
            // 현재 mid는 정답 후보! 더 큰 길이를 찾아보자
            answer = mid;
            low = mid + 1;
        } else {
            // N개도 못 만든다면? 너무 길게 자른 것! 길이를 줄이자.
            high = mid - 1;
        }
    }

    cout << answer;
    return 0;
}