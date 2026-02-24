#include <iostream>
#include <vector>
#include <queue>
#include <cmath> // abs 함수 사용을 위해 필요
#include <algorithm>
using namespace std;

int main() {
    int testcase;
    cin >> testcase;

    while (testcase--) {
        int n;
        cin >> n;

        vector<pair<int, int>> map(n + 2);
        for (int i = 0; i < n + 2; i++) {
            cin >> map[i].first >> map[i].second;
        }

        queue<int> q;
        vector<bool> visited(n + 2, false);

        q.push(0);
        visited[0] = true;

        bool possible = false;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            // 현재 위치(cur)에서 페스티벌(n+1)까지 바로 갈 수 있는지 확인
            if (abs(map[cur].first - map[n + 1].first) + 
                abs(map[cur].second - map[n + 1].second) <= 1000) {
                possible = true;
                break;
            }

            // 모든 편의점(1~n번)을 확인
            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    int dist = abs(map[cur].first - map[i].first) + 
                               abs(map[cur].second - map[i].second);
                    
                    if (dist <= 1000) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }

        if (possible) cout << "happy" << endl;
        else cout << "sad" << endl;
    }
    return 0;
}