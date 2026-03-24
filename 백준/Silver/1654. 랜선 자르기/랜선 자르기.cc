#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;

    vector<long long> lan(K, 0);
    for (int i = 0; i < K; i++)
        cin >> lan[i];

    sort(lan.begin(), lan.end());

    long long answer = 0;
    long long low = 1; // 랜선 길이가 0이 될 순 없으니, 최솟값 1에서 시작한다
    long long high = lan.back();

    // low와 high가 만날 때까지 검사한다
    while(low <= high){
        long long mid = low + (high - low) / 2;
        int cnt = 0;

        for (auto l : lan){
            cnt += l / mid;
        }

        if (cnt >= N){
            // 정답 업데이트
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer;
    return 0;
}