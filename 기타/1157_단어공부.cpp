#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string String;
	int arr[26] = {};
	int count = 0;
	int tempMax = 0;
	int index = 0;

	cin >> String;
	for (int i = 0; i < String.length(); i++){
		if ((int)String[i] > 90) // 소문자인 경우
			arr[(String[i] - 97)]++;
		arr[String[i] - 65]++; // 대문자인 경우
	}
	for (int j = 0; j < 26; j++) { // 가장 많이 사용 된 횟수 찾기
		if (tempMax < arr[j])
			tempMax = arr[j];
	}
	for (int k = 0; k < 26; k++)
		if (tempMax == arr[k]) count++;

	if (count - tempMax > 1) cout << "?"; // 여러개인 경우 ? 출력
	else {
		index = distance ( arr, find(arr, arr + 26, tempMax) ) ;
		cout << (char)(index + 65);
	}

}
