#include <string>
#include <vector>
using namespace std;

bool crossCheck(int row, int col, vector<int>& Location){
    for (int prevRow = 0; prevRow < row; prevRow++) {
        int prevCol = Location[prevRow];
        
        if (abs(row - prevRow) == abs(col - prevCol)) {
            return false;
        }
    }
    
    return true;
}

void dfs(vector<int>& Location, vector<bool>& Move, int n, int row, int& answer){
    if (row == n) {answer++; return;}
    
    // 이 행에서 방문 가능한 열이 있는지 체크
    for (int col = 0; col < n; col++){
        if (!Move[col]) continue;
        if (!crossCheck(row, col, Location)) continue;
        
        // 방문 가능하다면 방문
        // 퀸의 가로위치 전부, 퀸의 세로 위치 전부 방문 불가능 체크
        Location.push_back(col);
        Move[col] = false;
        
        dfs(Location, Move, n, row + 1, answer);
        Location.pop_back(); 
        Move[col] = true;
    }
}

// i회 반복해서 퀸을 찾는다.
// 즉, i회 반복 하면 i행에 퀸 자리를 찾으면 됨
int solution(int n) {
    int answer = 0;
    
    vector<int> Location;
    vector<bool> Move(n, true);
    // Location {1, 3, 0, 2}
    // Location[0] = 1, 0번째 행에서 1번째 열에 퀸이 위치
    
    dfs(Location, Move, n, 0, answer);
    
    return answer;
}