#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string N; // 정렬하려고 하는 수
    cin >> N;
    
    // 여기서, string의 개별 문자는 char이므로, 정렬 기준에 유의한다
    sort(N.begin(), N.end(), greater<char>());
    
    cout << N;
    
    return 0;
}