// 문제: N과 M (2)
// 유형: 백트래킹
// 난이도: 실버3

#include<iostream>
#include<vector>

#define endl "\n"
#define MAX 9
using namespace std;

int N, M;
bool Visit[MAX];
int Arr[MAX];

vector<int> V;

void DFS(int Idx, int Cnt){
    if (Cnt == M){
        for (int i = 0; i < V.size(); i++){
            cout << V[i] << " ";}
        cout << endl;
        return;
    }
    for (int i = Idx; i < N; i++){
        if (Visit[i] == true) continue;
        Visit[i] = true;
        V.push_back(i + 1);
        DFS(i, Cnt + 1);
        V.pop_back();
        Visit[i] = false;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    DFS(0, 0);

    return 0;
}
