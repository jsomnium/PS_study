#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size()); // 벡터 0으로 초기화
    stack<int> st; // 인덱스를 저장한다
    
    for (int index = 0; index < prices.size(); index++){
        if (st.empty()) {
            st.push(index);
            continue;
        }
        
        // 주식 가격이 떨어질 시
        while (!st.empty() && prices[st.top()] > prices[index]){
            answer[st.top()] = index - st.top();
            st.pop();
        }
        
        st.push(index);
    }
    
    while (!st.empty()){
        answer[st.top()] = prices.size() - st.top() - 1;
        st.pop();
    }
    
    return answer;
}