#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, less<int>> MaxHeap; // 최대힙
    priority_queue<int, vector<int>, greater<int>> MinHeap; // 최소힙
    int cnt = 0;

    for(int i = 0; i < operations.size(); i++){
        stringstream StringStream;
        StringStream.str(operations[i]); // 문자열 파싱
        string CheckString;
        StringStream >> CheckString;
        if (CheckString == "I"){ // 삽입
            StringStream >> CheckString;
            MaxHeap.push(stoi(CheckString));
            MinHeap.push(stoi(CheckString));
            cnt++;
        }
        else if (CheckString == "D" && cnt > 0){ // 삭제
            StringStream >> CheckString;

            if(CheckString == "-1"){ // 최솟값 삭제
                MinHeap.pop();
            }
            else if(CheckString == "1"){ // 최댓값 삭제
                MaxHeap.pop();
            }
            cnt--;

            if (cnt == 0){
                // Cnt가 0이 되는 경우에는 모든 힙에서 삭제해야 하므로
                // 추가로 pop 작업을 해준다.
                while(!MaxHeap.empty()){
                    MaxHeap.pop();
                }
                while(!MinHeap.empty()){
                    MinHeap.pop();
                }
            }
        }
    }

    // 연산 완료후
    if(cnt == 0){ // 큐가 빌 경우 [0, 0]
        answer.push_back(0);
        answer.push_back(0);
    }
    else{ // 큐가 비어있지 않을 경우 [Max, Min]
        answer.push_back(MaxHeap.top());
        answer.push_back(MinHeap.top());
    }

    // 정답 출력
    return answer;
}