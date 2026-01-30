#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int size = triangle.size();
    vector<vector<int>> DP(size, vector<int>(size, -1));
    DP[0][0] = triangle[0][0];
    
    /*
         0
       10 11
      20 21 22
     30 31 32 33
    40 41 42 43 44
    */
    
    
    for (int i = 1; i < size; i++){
        for (int j = 0; j <= i; j++){
            if (j <= 0){
                DP[i][j] = DP[i-1][j] + triangle[i][j];
            } else if (j >= i){
                DP[i][j] = DP[i-1][j-1] + triangle[i][j];
            } else {
                DP[i][j] = max(DP[i-1][j] + triangle[i][j], DP[i-1][j-1] + triangle[i][j]);
            }
        }
    }
        
    int answer = *max_element(DP[size-1].begin(), DP[size-1].end());
    return answer;
}