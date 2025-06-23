#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int big_max = 0, small_max = 0;
    
    for (int i = 0; i < sizes.size(); i++) {
        int width = min(sizes[i][0], sizes[i][1]);
        int height = max(sizes[i][0], sizes[i][1]);
        
        big_max = max(big_max, width);
        small_max = max(small_max, height);
    }
    
    return big_max * small_max;
}