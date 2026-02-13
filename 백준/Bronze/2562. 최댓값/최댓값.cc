#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max_val = -1; // 최댓값을 저장할 변수
    int max_idx = 0;  // 최댓값의 위치를 저장할 변수
    int input;

    for (int i = 1; i <= 9; i++) {
        cin >> input;
        
        // 현재 입력받은 값이 기존 최댓값보다 크면 업데이트
        if (input > max_val) {
            max_val = input;
            max_idx = i;
        }
    }

    cout << max_val << "\n" << max_idx << "\n";

    return 0;
}