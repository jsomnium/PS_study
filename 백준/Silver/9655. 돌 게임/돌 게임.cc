#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    // 홀수면 상근(SK), 짝수면 창영(CY)
    if (N % 2 == 1) {
        cout << "SK" << endl;
    } else {
        cout << "CY" << endl;
    }

    return 0;
}