#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    long long N, K;
    cin >> N >> K;

    long long low = 1;
    long long high = K;
    long long ans = 0;

    while (low <= high){
        long long mid = low + (high - low) / 2;
        long long cnt = 0;

        for (int i = 1; i <= N; i++){
            cnt += min(mid / i, N);
        }

        if (cnt >= K){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}