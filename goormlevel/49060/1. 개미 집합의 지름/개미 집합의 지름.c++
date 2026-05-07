#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> ants(N, 0);
    for (int i = 0; i < N; i++) cin >> ants[i];

    sort(ants.begin(), ants.end());

    int maxKept = 0;
    int left = 0;

    for (int right = 0; right < N; right++) {
        while (ants[right] - ants[left] > D) left++;

        maxKept = max(maxKept, right - left + 1);
    }

    cout << N - maxKept << endl;
    return 0;
}
