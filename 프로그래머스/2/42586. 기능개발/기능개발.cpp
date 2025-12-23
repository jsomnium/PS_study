#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> workDate;
    vector<int> answer;
    
    for (int i = 0; i < progresses.size(); i++){
        int leftProgress = 100 - progresses[i];
        int leftDate = 0;
        if (speeds[i] != 0){
            if (leftProgress % speeds[i] == 0) leftDate = leftProgress / speeds[i];
            else leftDate = leftProgress / speeds[i] + 1;
        }
        
        workDate.push(leftDate);
    }
    
    while(!workDate.empty()){
        int cnt = 1;
        int front = workDate.front();
        workDate.pop();
        
        while (!workDate.empty() && front >= workDate.front()){
            workDate.pop();
            cnt++;
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}