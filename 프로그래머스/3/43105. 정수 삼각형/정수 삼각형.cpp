#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int size = triangle.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));
    dp[0][0] = triangle[0][0];
    
    for (int i = 1; i < size; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0){
                dp[i][j] = triangle[i][j] + dp[i-1][j];
            } else if (j == i){
                dp[i][j] = triangle[i][j] + dp[i-1][j-1];
            } else {
            dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    
    int maxNum = 0;
    for (int k = 0; k < size; k++){
        maxNum = max(maxNum, dp[size-1][k]);
    }
    
    return maxNum;
}