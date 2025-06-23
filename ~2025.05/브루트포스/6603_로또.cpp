#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
 
#define endl "\n"
#define MAX 13
using namespace std;
 
int K;
int MAP[MAX];
bool Visit[MAX];
 
vector<int> V;
 
void Initialize(){ // 초기화
    V.clear();
    memset(MAP, 0, sizeof(MAP));
    memset(Visit, false, sizeof(Visit));
}
 
void Input(){
    for (int i = 0; i < K; i++)
        cin >> MAP[i];
}

void Select(int Idx, int Cnt){
    if (Cnt == 6){
        sort(V.begin(), V.end()); // 사전순으로 출력
        for (int i = 0; i < 6; i++)
        cout << V[i] << " ";
        cout << endl;
        return;
    }
    for (int i = Idx; i < K; i++){
        if (!Visit[i]){
            Visit[i] = true;
            V.push_back(MAP[i]);
            Select(i, Cnt+1);
            Visit[i] = false;
            V.pop_back();  
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    while (true){
        Initialize();
        cin >> K;
        if (K == 0) break;
        Input();
        Select(0, 0);;
        cout << endl;
    }
 
    return 0;
}