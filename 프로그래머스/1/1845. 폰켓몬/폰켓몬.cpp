#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums){
    set<int> s;
    int half = nums.size() / 2;
    
    for (auto n : nums){
        s.insert(n);
    }
    
    if (s.size() <= half){
        return s.size();
    } else {
        return half;
    }
}