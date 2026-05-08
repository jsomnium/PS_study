#include <string>
#include <vector>

using namespace std;

// 시계방향 90도 회전 코드
vector<vector<int>> rotate90(vector<vector<int>>& arr){
    int row = arr.size(), col = arr[0].size();
    
    vector<vector<int>> rotatedArr(col, vector<int>(row, 0));
    
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j)
            rotatedArr[j][row - 1 - i] = arr[i][j];
    }
    
    return rotatedArr;
}

// 자물쇠의 영역 내에서는 열쇠의 돌기 부분과 자물쇠의 홈 부분이 일치해야 한다
// 열쇠의 돌기와 자물쇠의 돌기가 만나서는 안된다
// 자물쇠의 모든 홈을 열쇠의 돌기로 채워야만 한다
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    // 90도 회전 경우 모두 고려하여 후보에 담기
    vector<vector<vector<int>>> candidates;
    vector<vector<int>> newArr(key);
    for (int rotate = 0; rotate < 4; ++rotate){
        candidates.push_back(newArr);
        newArr = rotate90(newArr);
    }
    
    // Lock의 채워야 하는 부분 구하기
    int lockCnt = 0;
    for (auto r : lock){
        for (auto c : r){
            if (c == 0) lockCnt++;
        }
    }
    
    // 탐색 시작
    for (auto candidate : candidates){
        int maxRowKey = candidate.size(), maxColKey = candidate[0].size();
        int maxRowLock = lock.size(), maxColLock = lock[0].size();
        
        for (int dr = -maxRowKey + 1; dr < maxRowLock; ++dr){
            for (int dc = -maxColKey + 1; dc < maxColLock; ++dc){
                int currentCnt = 0;
                bool isConflict = false;
                
                for (int r = 0; r < maxRowKey && !isConflict; ++r){
                    for (int c = 0; c < maxColKey && !isConflict; ++c){
                        int nxtR = r + dr;
                        int nxtC = c + dc;
                        
                        if (nxtR >= 0 && nxtR < maxRowLock && nxtC >= 0 && nxtC < maxColLock){
                            if (candidate[r][c] == 1 && lock[nxtR][nxtC] == 1) isConflict = true;
                            if (candidate[r][c] == 1 && lock[nxtR][nxtC] == 0) currentCnt++;
                        }
                    }
                }
                
                if (!isConflict && currentCnt == lockCnt) return true;
            }
        }
        
    }
    
    return false;
}