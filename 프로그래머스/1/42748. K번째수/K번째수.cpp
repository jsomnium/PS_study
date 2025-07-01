#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto command : commands){
        vector<int> result;
        int k = command[2] - 1;
        
        // 새로운 배열 만들기
        for (int i = command[0]-1; i <= command[1]-1; i++)
            result.push_back(array[i]);
        
        sort(result.begin(), result.end()); // 오름차순 정렬
        
        // K번째 수 찾기
        answer.push_back(result[k]);
    }
    
    return answer;
}