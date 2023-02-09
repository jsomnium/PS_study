#include <iostream>
using namespace std;

int main() {
	int N = 0; // N : 배달해야 할 킬로그램
	int numOfBag = 0; 	// numOfBag : 봉지의 개수
	while (N >= 0) {
		if (N % 5 == 0) { // 5로 나눠지면 그냥 5로 나누기
			numOfBag += (N / 5);
			cout << numOfBag << endl;
			return 0;
		}
		N -= 3; // 5로 나눠지지 않으면 3키로그램 봉지에 담고 다시 5키로그램으로 나눠보기
		numOfBag++;
	}
	cout << -1 << endl;
}