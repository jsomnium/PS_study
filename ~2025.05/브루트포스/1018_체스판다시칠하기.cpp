#include<iostream>
#include<algorithm>
using namespace std;

int chess[51][51]; // 0: 검은색, 1: 하얀색

int check(int x,int y){
	int cnt1 = 0;
	int cnt2 = 0;

	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if ((i + j) % 2 == chess[i][j]) cnt1++; // 탐색을 시작하는 첫번째 블록이 흰색 일때
			if ((i + j + 1) % 2 == chess[i][j]) cnt2++; // 탐색을 시작하는 첫번째 블록이 검정색 일때
		}
	}

	return min(cnt1, cnt2); // 둘 중 최솟값 반환
}

int main(){
	int N, M;
	int mini = 64; // 최소 값
	char c;

	cin >> N >> M;

	for (int i = 0; i < N; i++) { // 입력받고 저장하기
		for (int j = 0; j < M; j++) {
			cin >> c;
			if (c == 'B') chess[i][j] = 0; // Black => 0
			else chess[i][j] = 1; // White => 1
		}
	}

	for (int i = 0; i < N-7; i++) { // 8*8 이 되어야 하므로 N-7, M-7 까지만 탐색
		for (int j = 0; j < M-7; j++) {
			if (mini > check(i, j)) mini = check(i, j); // 가장 작은 값인지 판별
		}
	}

	cout << mini;
}