// 문제: 숨바꼭질
// 유형: BFS
// 난이도: 실버1

#include <iostream>
#include <queue>
using namespace std;

int n, k;
bool visit[100001]; // 방문 체크

void bfs(int start){
    queue<pair<int, int>> q; // <수빈이의 위치, 소요 시간>
    q.push(make_pair(start, 0)); // start 지점에서 0의 시간에 시작

    while(!q.empty()){
        int x = q.front().first; // x : 위치
        int cnt = q.front().second; // cnt : 시간
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
        } // 모두 탐색
    }
}
int main(){
    cin >> n >> k;
    bfs(n);
    return 0;
}