#include <iostream>
#include <vector>
#include <stack>;
using namespace std;

vector<int> solution(vector<int> prices) {
    stack<int> st;
    int size = prices.size();
    vector<int> answer(size);
    
    for (int i = 0; i < size; i++){
        while (!st.empty() && prices[i] < prices[st.top()]){
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        answer[st.top()] = size - st.top() - 1;
        st.pop();
    }
    return answer;
}