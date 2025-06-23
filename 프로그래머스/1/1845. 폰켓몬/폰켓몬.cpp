#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int numOfType = 0;
    int numsHalf = nums.size() / 2;
    
    sort(nums.begin(), nums.end());
    
    for (int i = 1; i <= nums.size(); i++){
        if (nums[i] != nums[i-1]){
            numOfType++;
        }
    }
    
    if (numsHalf <= numOfType){
        answer = numsHalf;
    } else if (numsHalf > numOfType){
        answer= numOfType;
    }
    
    return answer;
}