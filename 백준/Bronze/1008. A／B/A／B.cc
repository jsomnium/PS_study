#include <iostream>

using namespace std;

int main() {
    double A, B;
    cin >> A >> B;

    // 소수점 출력 설정
    cout.fixed;          // 소수점 아래 자리수를 고정하겠다는 의미
    cout.precision(12);  // 소수점 아래 12자리까지 출력 (9자리 이상이면 안전)

    if (B != 0) {
        cout << A / B << endl;
    }

    return 0;
}