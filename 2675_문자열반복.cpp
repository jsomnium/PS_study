#include <iostream>
using namespace std;

int main(){
    int TestCase; // 테스트 케이스의 개수
    int Repeat; // 문자 반복 회수
    string String = {};

    cin >> TestCase;

    for (int i = 0; i < TestCase; i++) {
        cin >> Repeat >> String;
        for (int j = 0; j < String.length(); j++) {
            for (int k = 0; k < Repeat; k++)
                cout << String[j];
        }
        cout << endl;
    }
}