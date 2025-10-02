#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxRow = 0;
    int maxCol = 0;
    
    for (auto size : sizes){
        maxRow = max(maxRow, max(size[0], size[1]));
        maxCol = max(maxCol, min(size[0], size[1]));
    }
    
    return maxRow * maxCol;
}