#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> liquids(n);
    for (int i = 0; i < n; i++) {
        cin >> liquids[i];
    }

    // 정렬은 필수!
    sort(liquids.begin(), liquids.end());

    int left = 0;
    int right = n - 1;

    int min_sum = 2000000000; 
    int ans1 = liquids[left];
    int ans2 = liquids[right];

    while (left < right) {
        int sum = liquids[left] + liquids[right];

        if (abs(sum) < min_sum) {
            min_sum = abs(sum);
            ans1 = liquids[left];
            ans2 = liquids[right];
        }

        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    // 결과 출력
    cout << ans1 << " " << ans2 << "\n";

    return 0;
}