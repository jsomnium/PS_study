// 문제: N과 M (3)
// 유형: 백트래킹
// 난이도: 실버3

#include<iostream>
#include<vector>

#define endl "\n"
#define MAX 8
using namespace std;

int N, M;
vector<int> V;

void DFS(int Cnt){
    if (Cnt == M){
        for (int i = 0; i < V.size(); i++){
            cout << V[i] << " ";}
        cout << endl;
        return;
    }
    for (int i = 1; i <= N; i++){
        V.push_back(i);
        DFS(Cnt + 1);
        V.pop_back();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    DFS(0);

    return 0;
}