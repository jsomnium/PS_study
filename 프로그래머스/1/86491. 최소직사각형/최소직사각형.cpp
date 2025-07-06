#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int row = 0;
    int col = 0;
    
    for (int i = 0; i < sizes.size(); i++){
        if (row == 0){
            row = max(sizes[i][0], sizes[i][1]);
            col = min(sizes[i][0], sizes[i][1]);
        } else {
            row = max(row, (max(sizes[i][0], sizes[i][1])));
            col = max(col, (min(sizes[i][0], sizes[i][1])));
        }
    }
    
    return row * col;
}