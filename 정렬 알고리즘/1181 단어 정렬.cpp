// 문제: 단어 정렬
// 유형: 문자열, 정렬
// 난이도: 실버5

// 해당 문제를 풀기 위해 알아야 하는 것: string 정렬 방법
// 중복된 단어를 하나만 남기고 제거하는 효과적인 방법

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comparison(string a, string b){
    if (a.length() == b.length())
        return a < b; // 알파벳 순서로 정렬
    return a.length() < b.length(); // 길이 순서로 정렬
    
}
int main(){
    int n;
    vector<string> v;
    string str;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> str;
        if (find(v.begin(),v.end(),str) == v.end())
            v.push_back(str); // 중복 단어가 없는 경우만 push
    }

    sort(v.begin(), v.end(), comparison); // 정렬하기

    for (auto num : v){ // 출력하기
        cout << num << '\n';
    }

    return 0;
}