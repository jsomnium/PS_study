#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// S층에서 G층으로 가기 위해 눌러야 하는 버튼 수의 최솟값
int main(){
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    // F: 스타링크 건물 총 층수
    // G: 스타링크 위치 층수
    // S: 강호의 층수
    // U: U층 위로
    // D: D층 위로

    queue<pair<int, int>> q;
    vector<bool> visited(F + 1, false);

    int position = S;
    int count = 0;

    // BFS 탐색 시작
    q.push({position, 0});
    visited[position] = true;

    while (!q.empty()){
        position = q.front().first;
        count = q.front().second;
        q.pop();

        if (position == G){
            cout << count << endl;
            return 0;
        }

        if (position + U <= F && visited[position + U] == false){
            q.push({position + U, count + 1});
            visited[position + U] = true;
        }
        
        if (position - D > 0 && visited[position - D] == false) {
            q.push({position - D, count + 1});
            visited[position - D] = true;
        }
    }

    cout << "use the stairs" << endl;
    return 0;
}