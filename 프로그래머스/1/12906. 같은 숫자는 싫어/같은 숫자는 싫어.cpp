#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    
    for (auto a : arr){
        if (q.empty() == true || !q.empty() && (q.back() != a)){
            q.push(a);
        } 
    }
    
    int qSize = q.size();
    for (int i = 0; i < qSize; i++){
        answer.push_back(q.front());
        q.pop();
    }

    return answer;
}