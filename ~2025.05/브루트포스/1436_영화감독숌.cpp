#include<iostream>
using namespace std;

int main(){
	int N, ans, cnt, temp;
	cin >> N;

	ans = 0; // 영화 제목
	cnt = 0; // 현재 몇번째 종말의 수인지

	while (cnt != N){ // N번째 종말의 수를 구할 때 까지
		ans++;
		temp = ans;

		while (temp != 0){
			if (temp % 1000 == 666){ // 종말의 숫자라면 cnt 증가
				cnt++;
				break;
			}
			else temp /= 10; // 0이 될 때 까지 일의 자리수 삭제하여 나눠지는지 판별하기
		}
	}
	cout << ans;
}