// 문제: N과 M (4)
// 유형: 백트래킹
// 난이도: 실버3

#include<iostream>
#include<vector>

#define endl "\n"
#define MAX 8
using namespace std;

int N, M;
vector<int> V;

void DFS(int num,int Cnt){
    if (Cnt == M){
        for (int i = 0; i < M; i++)
            cout << V[i] << " ";
        cout << endl;
        return;
    }
    for (int i = num; i <= N; i++){
        V.push_back(i);
        DFS(i, Cnt + 1);
        V.pop_back();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    DFS(1, 0);

    return 0;
}