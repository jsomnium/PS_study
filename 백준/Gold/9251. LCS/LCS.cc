#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int sizeA = (int)a.size();
    int sizeB = (int)b.size();

    vector<vector<int>> DP(sizeA + 1, vector<int>(sizeB + 1, 0));

    for (int i = 1; i <= sizeA; i++) {
        for (int j = 1; j <= sizeB; j++) {
            if (a[i - 1] == b[j - 1]) {
                // 문자가 같으면 대각선 위 + 1
                DP[i][j] = DP[i - 1][j - 1] + 1;
            } else {
                // 문자가 다르면 왼쪽 vs 위쪽 중 큰 값
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    cout << DP[sizeA][sizeB];

    return 0;
}