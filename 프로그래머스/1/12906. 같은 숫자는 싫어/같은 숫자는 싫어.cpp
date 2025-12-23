#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> st;
    
    for (auto a : arr){
        if (st.empty()) st.push(a);
        else if (st.top() != a) {st.push(a);}
    }
    
    vector<int> ans;
    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    reverse(ans.begin(), ans.end());    
    return ans;
}