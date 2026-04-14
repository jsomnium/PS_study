#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int numbers[11];
int operators[4]; // +, -, *, / 순서
int max_val = -1000000001;
int min_val = 1000000001;

// idx: 현재 계산에 사용할 숫자의 인덱스
// current_result: 현재까지 계산된 결과 값
void solve(int idx, int current_result) {
    // 모든 숫자를 다 사용했을 경우 (기저 사례)
    if (idx == N) {
        max_val = max(max_val, current_result);
        min_val = min(min_val, current_result);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) {
            operators[i]--; // 연산자 하나 사용

            if (i == 0) solve(idx + 1, current_result + numbers[idx]);
            else if (i == 1) solve(idx + 1, current_result - numbers[idx]);
            else if (i == 2) solve(idx + 1, current_result * numbers[idx]);
            else if (i == 3) solve(idx + 1, current_result / numbers[idx]);

            operators[i]++; // 재귀 종료 후 연산자 개수 복구 (백트래킹)
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    // 첫 번째 숫자를 초기값으로 설정하고 탐색 시작
    solve(1, numbers[0]);

    cout << max_val << "\n" << min_val << endl;

    return 0;
}