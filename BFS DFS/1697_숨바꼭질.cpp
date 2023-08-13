// 문제: 숨바꼭질
// 유형: BFS
// 난이도: 실버1

#include <iostream>
#include <queue>
using namespace std;

int n, k;
bool visit[100001]; // 방문 체크

void bfs(int a){
    queue<pair<int, int>> q; // <수빈이의 위치, 걸리는 시간>
    q.push(make_pair(a, 0)); // a위치에서 0시간 => 기본 시작

    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(x == k){
            cout << cnt;
            break;
        }
        if(x + 1 >= 0 && x+1 < 100001){
            if(!visit[x+1]){
                visit[x + 1] = true;
                q.push(make_pair(x + 1, cnt + 1));
            }
        }
        if( x-1 >= 0 && x-1 < 100001){
            if(!visit[x-1]){
                visit[x - 1] = true;
                q.push(make_pair(x - 1, cnt + 1));
            }
        }
        if( 2*x >=0 && 2*x < 100001){
            if(!visit[2*x]){
                visit[2*x] = true;
                q.push(make_pair(2 * x, cnt + 1));
            }
        } // 각 다음 좌표마다 q에 넣어줘서 모두 탐색
    }
}
int main(){
    cin >> n >> k;
    visit[n] = true; // 종료 시점
    bfs(n);
    return 0;
}