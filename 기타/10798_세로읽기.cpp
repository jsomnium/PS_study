// 문제: 세로읽기
// 유형: 구현, 문자열
// 난이도: 브론즈1

#include <iostream>
#include <string>
using namespace std;

string word[5];

int main() {	
	for(int i=0;i<5;i++)
		cin>>word[i];
	for(int i=0;i<15;i++){
		for(int j=0;j<5;j++){
			if(word[j].length()>i)
				cout<<word[j][i];		
		}
	}
	return 0;
}