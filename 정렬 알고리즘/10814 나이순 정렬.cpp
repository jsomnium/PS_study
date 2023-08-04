// 문제: 나이순 정렬
// 유형: 안정 정렬, 정렬
// 난이도: 실버5

// 주의할 점
// 나이가 같으면 가입한 순서대로 출력해야 한다.
// 나이순으로 정렬하면 그 뒤에는 입력한 순서대로 정렬된다고 착각하기 쉽다.
// 하지만 sort는 불안정 정렬로, 안정 정렬을 보장하지 않는다.
// 따라서 안정 정렬을 보장하는 stable_sort 함수를 사용한다.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int,string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(){
    int N;
    pair <int,string> tmp;
    vector<pair<int, string> > member;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> tmp.first >> tmp.second;
        member.push_back(tmp);
    }
    stable_sort(member.begin(), member.end(), comp);
    for (auto a : member)
        cout << a.first << ' ' << a.second << '\n';
}