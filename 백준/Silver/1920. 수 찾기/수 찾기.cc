#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    // 1. 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N)) return 0; // 입력 예외 처리

    vector<int> arr(N);
    for (int n = 0; n < N; n++)
        cin >> arr[n];

    sort(arr.begin(), arr.end());

    cin >> M;
    for (int m = 0; m < M; m++) {
        int checkNum;
        cin >> checkNum;

        int low = -1;
        int high = arr.size();

        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= checkNum) {
                high = mid;
            } else {
                low = mid;
            }
        }
        
        // 2. endl 대신 '\n' 사용
        if (high < arr.size() && arr[high] == checkNum) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}