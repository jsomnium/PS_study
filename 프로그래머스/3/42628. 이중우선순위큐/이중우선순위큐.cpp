#include <string>
#include <vector>
#include <set> // multiset은 set 헤더에 있습니다
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms; // 오름차순 자동 정렬되는 컨테이너

    for(string op : operations){
        stringstream ss(op);
        string cmd;
        int num;
        ss >> cmd >> num;

        if (cmd == "I"){
            ms.insert(num); // 삽입 (자동 정렬됨)
        }
        else if (cmd == "D" && !ms.empty()){
            if(num == 1){
                // 최댓값 삭제: 맨 뒤 요소(end 바로 앞) 삭제
                // --ms.end() 혹은 prev(ms.end()) 사용
                ms.erase(prev(ms.end())); 
            }
            else if(num == -1){
                // 최솟값 삭제: 맨 앞 요소(begin) 삭제
                ms.erase(ms.begin());
            }
        }
    }

    if(ms.empty()){
        return {0, 0};
    } else {
        // {최댓값, 최솟값}
        return {*ms.rbegin(), *ms.begin()};
    }
}