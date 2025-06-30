#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    // progresses를 100에서 빼고, speed로 나누면 몫이 남은 일수이다.
    // 나머지가 있는 경우에는, +1
    // 만약, 93이 들어오면 (100-93 = 7)이므로 7이 남은 작업 일수이다. [7]
    // 만약, 30이 들어오면 (100-30 = 70) 이므로 (70/30 = 2 이고 나머지 10) 따라서 3일이 남은 작업 일수이다. [3]
    // 만약, 55가 들어오면 44 / 5 = 8에 나머지까지 생각하면 9일이다. [8]
    
    // 배포되어야 하는 순서대로 배포되어야 한다.
    // 따라서 먼저 들어간 게 먼저 나와야 하므로 선입선출 queue 사용
    
    for (int i = 0; i < progresses.size(); i++){
        int day = 0;
        day = 100 - progresses[i];
        cout << "day : " << day << endl;
        
        if (day % speeds[i] == 0){
            day = day/speeds[i];
        } else {
            day = day/speeds[i] + 1;
        }
        
        q.push(day);
        
        cout << i << "st final day : " << day << endl;
    }
    
    while (!q.empty()){
        int front = q.front();
        q.pop();
        int count = 1;
        
        while (!q.empty() && front >= q.front()){
            q.pop();
            count++;
        }
        
        answer.push_back(count);
    }
    
    return answer;
}