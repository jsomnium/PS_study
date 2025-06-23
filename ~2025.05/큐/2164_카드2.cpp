// 문제: 카드2
// 유형: 큐
// 난이도: 실버4

// 선입선출 방식인 큐를 사용하여 풀이한다

#include<iostream>
#include<queue>
using namespace std;

int main(){
    int N;
    int arr[500001];
    queue<int> q;
    
    cin >> N;

    for (int i = 1; i <= N; i++)
        q.push(i); // 큐에 순서대로 push

    while(q.size()>1){ // 큐에 하나만 남을 때 까지
        q.pop(); // 맨 앞의 것 빼기
        q.push(q.front()); // 뒤에 넣어주기
        q.pop(); // 빼기
    }

    cout << q.front();
}