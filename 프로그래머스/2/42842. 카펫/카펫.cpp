#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int size = brown + yellow;
    // 카펫의 넓이(격자의 개수)
    
    // 최소 길이 3부터 시작해서 최대 길이까지 조건을 만족하는 경우 찾기
    for (int height = 3; height <= size / 2; ++height){
        int width = size / height;
        
        // 나누어 떨어지는 경우만 가능성 있음
        if (size % height == 0 && width >= height){
            if (yellow == (width - 2) * (height - 2)){
                answer.push_back(width);
                answer.push_back(height);
            }
        }
    }
    
    // 카펫의 (가로 >= 세로)
    // 한 칸의 넓이는 1
    // 가로*세로 = 브라운 + 옐로우
    
    // 카펫의 가로 길이 = x
    // 카펫의 세로 길이 = y
    // brown 격자의 개수 = B
    // yellow 격자의 개수 = Y
    // 전체 카펫 격자의 개수 = xy = B + Y
    // 그런데, yellow 격자의 가로, 세로에서 2를 더해서 곱하면 전체 카펫과 같으므로
    // (x-2)(y-2) = Y
    // xy - 2y - 2x + 4 = Y
    
    // 48 - 2y - 2x + 4 = 24
    // -2y -2x = 28
    // x + y = 14
    // xy = 48
    // y = 14-x
    // x(14-x) = 48
    // x^2 - 14x + 48
    // 
    
    
    return answer;
}