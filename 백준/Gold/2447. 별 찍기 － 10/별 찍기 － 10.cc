#include <vector>
#include <iostream>
#include <string>

using namespace std;

void recursion(vector<vector<char>> &map, int x, int y, int N) {
    if (N == 1) return;

    int size = N / 3;

    // 3x3 격자로 나누어 생각하기
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // 가운데 칸 (i==1, j==1)인 경우 공백 처리
            if (i == 1 && j == 1) {
                for (int r = x + size; r < x + 2 * size; r++) {
                    for (int c = y + size; c < y + 2 * size; c++) {
                        map[r][c] = ' ';
                    }
                }
            } 
            // 나머지 8개 칸은 다시 재귀 호출
            else {
                recursion(map, x + i * size, y + j * size, size);
            }
        }
    }
}

int main(){
    int N;
    cin >> N;

    // N * N 사이즈만큼 별 찍어두고 재귀 호출
    vector<vector<char>> map(N, vector<char>(N, '*'));
    recursion(map, 0, 0, N);

    // 출력하기
    for (auto m : map){
        for (char star : m){
            cout << star;
        }
        cout << endl;
    }

    return 0;
}