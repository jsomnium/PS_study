#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int A, P;
    cin >> A >> P;

    vector<int> D; // 숫자를 순서대로 저장
    set<int> D_set; // 중복 체크용

    int current = A;

    // 중복된 숫자를 찾을 때까지 반복
    while (D_set.count(current) == 0) {
        D_set.insert(current);
        D.push_back(current);

        int nextNum = 0;
        int temp = current;

        // 자릿수 분리 및 P제곱 합 계산
        while (temp > 0) {
            int digit = temp % 10;
            int multi = 1;
            for (int j = 0; j < P; j++) multi *= digit;
            nextNum += multi;
            temp /= 10;
        }
        current = nextNum;
    }

    // 반복이 시작된 숫자(current)가 벡터의 몇 번째 인덱스에 있는지 찾기
    for (int i = 0; i < D.size(); i++) {
        if (D[i] == current) {
            cout << i << endl; // 인덱스가 곧 "앞에 남은 숫자의 개수"
            return 0;
        }
    }

    return 0;
}