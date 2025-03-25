#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> stacks;
    // 가장 최근에 vector에 넣은 요소를 추적하기 위해 stack 사용

    for (auto num: arr){
        if (answer.empty() || stacks.top() != num){
            stacks.push(num);
            answer.push_back(num);
        }
        // 1. 배열이 비어있는 경우, 수 push
        // 2. 배열에 넣을 수가 stack의 top(가장 최근에 배열에 넣은 수)가 아닌 경우, push
    }
    return answer;
}
