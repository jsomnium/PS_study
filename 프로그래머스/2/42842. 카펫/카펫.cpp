#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int totalSize = brown + yellow;
    
    for (int i = 3; i <= totalSize / 2; i++){
        if (totalSize % i == 0){
            int totalWidth = max(i, totalSize / i);
            int totalHeight = min(i, totalSize / i);
            
            if ((totalWidth - 2) * (totalHeight - 2) == yellow){
                answer.push_back(totalWidth);
                answer.push_back(totalHeight);
                break;
            }
        }
    }
    
    return answer;
}
