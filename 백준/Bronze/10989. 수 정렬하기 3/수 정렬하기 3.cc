#include <iostream>

using namespace std;

// 숫자의 범위가 10,000 이하라고 가정할 때
int counts[10001]; 

int main() {
    // 입출력 최적화 (필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int max_num = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        counts[num]++; // 배열의 인덱스를 숫자로 사용
        
        // 입력된 최대 숫자를 기억해두면 나중에 출력 범위를 줄일 수 있음
        if (num > max_num) max_num = num;
    }

    // 0부터 입력된 최대 숫자까지 확인
    for (int i = 0; i <= max_num; i++) {
        // 해당 숫자가 입력된 횟수만큼 반복 출력
        while (counts[i] > 0) {
            cout << i << '\n';
            counts[i]--;
        }
    }

    return 0;
}