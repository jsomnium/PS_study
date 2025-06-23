// 문제: 프로그래머스_주식가격
// 유형: 스택
// 난이도: 레벨2

#include <iostream>
#include <vector>
#include <stack>;
using namespace std;

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

// 아래는 이중 포문을 이용한 풀이

/*
#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int length = prices.size();

    for (int i = 0; i < length; i++){
        int temp = 0;
        for (int j = i + 1; j < length; j++){
            if (prices[i] > prices[j]) {
                temp++;
                break;
            } else {
                temp++;
            }
        }
        answer.push_back(temp);
    }

    return answer;
}
*/