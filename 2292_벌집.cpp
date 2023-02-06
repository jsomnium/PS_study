#include <iostream>
using namespace std;
int main() {
	int N = 0; // 입력받는 수
	int passingRoom = 0; // 지나가는 방의 개수

	cin >> N;

	int cnt = 0;

	if ( N == 1) cout << 1;
	else{
		while ( N - (6 * cnt) > 0 ) {
			
			cnt ++;
		}
		
	cout << cnt;
	}


}