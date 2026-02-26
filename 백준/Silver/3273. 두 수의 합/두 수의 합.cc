#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> x;

    // 1. 오름차순 정렬
    sort(a.begin(), a.end());

    int left = 0;
    int right = n - 1;
    int count = 0;

    // 2. 투 포인터 탐색
    while (left < right) {
        int sum = a[left] + a[right];

        if (sum == x) {
            count++;
            left++;
            right--;
        } else if (sum < x) {
            left++; // 합이 작으면 왼쪽 포인터를 오른쪽으로
        } else {
            right--; // 합이 크면 오른쪽 포인터를 왼쪽으로
        }
    }

    cout << count << "\n";

    return 0;
}