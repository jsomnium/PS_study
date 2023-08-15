// 문제: 최댓값
// 유형: 구현
// 난이도: 브론즈3

#include <iostream>
using namespace std;

int main(){
    int arr[9][9] = {};
    int max = -1; // 모든 수가 0일 수 있으므로 -1로 초기화한다.
    int position_i,position_j;

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cin >> arr[i][j];
            if (arr[i][j] > max) {
                max = arr[i][j];
                position_i = i + 1; // 1번째 행부터 시작하므로 +1
                position_j = j + 1; // 1번째 열부터 시작하므로 +1
            }
        }
    }
    cout << max << "\n" << position_i << " " << position_j << endl;
}