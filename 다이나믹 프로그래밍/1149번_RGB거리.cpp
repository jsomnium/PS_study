// 문제: RGB 거리
// 유형: 다이나믹 프로그래밍
// 난이도: 실버1

#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b){
    return a < b ? a : b;
}

int main(){
    int N;
    int house[1001][3]; // i번째 집의 색을 j색으로 칠할 때의 비용

    cin >> N; // 집의 수 입력받기
    for (int i = 0; i < N; i++){
        int Rcost, Gcost, Bcost;
        cin >> Rcost >> Gcost >> Bcost; // 비용 입력받기

        if (i == 0){ // 최소 비용 구하기
            house[i][0] = Rcost;
            house[i][1] = Gcost;
            house[i][2] = Bcost;
        } else {
            house[i][0] = min(house[i-1][1], house[i-1][2]) + Rcost;
            house[i][1] = min(house[i-1][0], house[i-1][2]) + Gcost;
            house[i][2] = min(house[i-1][0], house[i-1][1]) + Bcost;
        }
    }

    cout << min(house[N-1][2],min(house[N-1][0],house[N-1][1]));
}