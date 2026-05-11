#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate90 (vector<vector<int>>& arr){
    int row = arr.size();
    int col = arr[0].size();
    
    vector<vector<int>> rotatedArr(col, vector<int>(row, 0));
    
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j)
            rotatedArr[j][row-1-i] = arr[i][j];
    }
    
    return rotatedArr;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<vector<vector<int>>> candidates;
    vector<vector<int>> newArr(key);
    
    for (int rotate = 0; rotate < 4; ++rotate){
        candidates.push_back(newArr);
        newArr = rotate90(newArr);
    }
    
    int lockCnt = 0;
    for (auto r : lock){
        for (auto c : r)
            if (c == 0) lockCnt++;
    }
    
    for (auto candidate : candidates){
        int maxRowKey = candidate.size();
        int maxColKey = candidate[0].size();
        int maxRowLock = lock.size();
        int maxColLock = lock[0].size();
        
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