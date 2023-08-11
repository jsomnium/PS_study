// 문제: 카드 구매하기2
// 유형: 다이나믹 프로그래밍
// 난이도: 실버1

// 카드 구매하기1 과 차이점은 최댓값, 최솟값에 있다.
// 이때, DP의 초기값을 cost로 정함에 주의한다.

#include <iostream>
using namespace std;

int min(int a, int b){
    return a < b ? a : b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 구매하고자 하는 카드의 개수
    cin >> N;
    int cost[10001]; // cost[i] : 카드 i팩의 가격
    int DP[10001]; // DP[i] : i개 카드를 구매할 때의 최소 비용

    for (int i = 1; i <= N; i++){
        cin >> cost[i];
        DP[i] = cost[i]; // DP의 초기값을 cost로 정한다.
    }

    cost[0] = 0;

    for (int i = 1; i <= N; i++){ // 총 i개의 카드를 구매하려고 할 때,
        for (int j = 1; j <= i; j++){ // 마지막에 j팩 카드를 한 장 산다.
            DP[i] = min(DP[i], DP[i-j] + cost[j]); // 뭐가 더 큰지 비교
        }
    }

    cout << DP[N];
}