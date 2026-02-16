#include <iostream>
#include <cmath>

using namespace std;

// n: 원판 개수, from: 출발지, bypass: 경유지, to: 목적지
void hanoi(int n, int from, int bypass, int to) {
    if (n == 1) {
        // 원판이 1개면 바로 목적지로 이동 (Base Case)
        cout << from << " " << to << "\n";
        return;
    }

    // 1. n-1개를 경유지로 이동
    hanoi(n - 1, from, to, bypass);

    // 2. 가장 큰 원판을 목적지로 이동
    cout << from << " " << to << "\n";

    // 3. 경유지에 있던 n-1개를 다시 목적지로 이동
    hanoi(n - 1, bypass, from, to);
}

int main() {
    int n;
    cin >> n;

    // 총 이동 횟수: 2^n - 1
    cout << (int)pow(2, n) - 1 << "\n";

    hanoi(n, 1, 2, 3);

    return 0;
}