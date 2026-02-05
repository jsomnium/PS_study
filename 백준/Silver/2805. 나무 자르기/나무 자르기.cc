#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, v[1'000'000];

// 결정 문제
bool Check(const int mid) { // mid 높이에 절단기를 위치했을 때 m 이상의 나무를 얻을 수 있는가?
    long long sum = 0; // 오버플로우 조심
    for (int i = 0; i < n; i++) {
        if (v[i] > mid) sum += v[i] - mid;
    }
    return sum >= m;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];

    // 이분 탐색
    int lo = 0, hi = 1e9;
    // Checklist
    // 1. Check(lo) = T, Check(hi) = F를 만족하는가?
    // 2. lo는 정답이 될 수 있는 모든 범위를 나타낼 수 있는가? (정답은 0 ~ max(v) - 1라 가능)

    while (lo + 1 < hi) { // lo와 hi 사이에 다른 칸이 존재하는가?
        int mid = (lo + hi) / 2; // 항상 lo < mid < hi를 만족 (평균을 생각해보면 o)
        if (Check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << '\n';
}