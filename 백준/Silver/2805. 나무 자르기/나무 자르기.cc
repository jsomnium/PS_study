#include <iostream>
#include <algorithm>
#include <vector> // 추가!

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    vector<long long> tree(N);
    long long high = 0;
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        if (tree[i] > high) high = tree[i];
    }

    long long low = 0;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long total_height = 0;

        for (auto t : tree) {
            if (t > mid) {
                total_height += (t - mid);
            }
        }

        if (total_height >= M) {
            ans = mid;      
            low = mid + 1;  
        } else {
            high = mid - 1;
        }
    }

    cout << ans;
    return 0;
}