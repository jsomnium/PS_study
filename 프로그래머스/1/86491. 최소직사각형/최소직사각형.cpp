#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxRow = 0;
    int maxCol = 0;
    
    for (auto s : sizes){
        maxRow = max(maxRow, max(s[0], s[1]));
        maxCol = max(maxCol, min(s[0], s[1]));
    }
    
    return maxRow * maxCol;
}