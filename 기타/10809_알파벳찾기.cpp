#include <iostream>
using namespace std;

int main() {
    int arr[26]; // 알파벳 개수 카운트 배열
    fill_n(arr, 26, -1); // 값을 전부 -1로 초기화
    string S;
    cin >> S;
    for (int i = 0; i < S.length(); i++)
        if (arr[(int)S[i] - 97] < 0) arr[(int)S[i] - 97] = i;
    for (int j = 0; j < 26; j++)
        cout << arr[j] << " ";
}