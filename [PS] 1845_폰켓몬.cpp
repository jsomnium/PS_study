#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int maxOfPocketmonType = nums.size()/2;
    vector<int> pocketmonType = {};

    for (int i = 0; i < nums.size(); i++){
        if (std::find(pocketmonType.begin(), pocketmonType.end(), nums[i])
            == pocketmonType.end()) pocketmonType.push_back(nums[i]); }
    // std::find는 요소를 찾으면 해당 위치의 반복자(iterator)를 반환한다.
    // 요소가 없으면 .end()를 반환한다.
    
    return min((int)pocketmonType.size(), maxOfPocketmonType);
}
