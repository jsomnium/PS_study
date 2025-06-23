#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// i번째 수 부터 j번째 수를 정렬하여 k번째 숫자를 return 하는 함수
int def (vector<int> array, vector<int> v){
    vector<int> newV;
    int j = v[1] - 1;
    for (int i = v[0] - 1; i <= j; i++){
        newV.push_back(array[i]);
    }
    sort(newV.begin(), newV.end()); // 오름차순 정렬
    
    return newV[v[2] - 1];
    // k번째 수 출력

    // 모두 '번째' 수 이므로 -1을 해준다
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++){
        answer.push_back(def(array, commands[i]));
    }

    return answer;
}
