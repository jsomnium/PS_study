#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// 전역이나 참조로 문자열을 관리하면 편합니다.
void solve(string& str, int start, int len) {
    // 기저 조건: 길이가 1이면 더 이상 나눌 게 없음
    if (len == 1) return;

    int part = len / 3; // 3등분한 한 구간의 길이

    // 1. 가운데 구간을 공백으로 바꿉니다.
    // 시작 인덱스: start + part
    // 바꾸는 개수: part 개
    for (int i = start + part; i < start + 2 * part; i++) {
        str[i] = ' ';
    }

    // 2. 왼쪽 구간 재귀 호출
    solve(str, start, part);

    // 3. 오른쪽 구간 재귀 호출
    solve(str, start + 2 * part, part);
}

int main() {
    // 입출력 최적화 (N이 커질 수 있으므로 필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // 입력이 없을 때까지 계속 읽기
    while (cin >> N) {
        int total_len = pow(3, N); // 3의 N승 계산
        
        // 처음엔 전부 '-'로 채워진 문자열 생성
        string str(total_len, '-');

        // 재귀 시작 (시작 위치 0, 전체 길이 전달)
        solve(str, 0, total_len);

        // 결과 출력
        cout << str << "\n";
    }

    return 0;
}