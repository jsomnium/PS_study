#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (string a, string b){
    int bigA = stoi(a + b);
    int bigB = stoi(b + a);
    
    return bigA > bigB;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;

    for (int num : numbers){
        nums.push_back(to_string(num));
    }
    
    sort(nums.begin(), nums.end(), comp);
    
    for (auto n: nums){
        answer += n;
    }
    
    if (answer[0] == '0'){
        answer = '0';
    }
    
    return answer;
}