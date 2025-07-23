#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int num = number.length() - k; // 구해야할 숫자 크기
    int idx = 0;
    
    // num 개의 숫자 고르기
    for(int i = 0; i < num; i++){
        // 제일 큰 수 고르기
        char maxChar = number[idx]; // 제일 처음에 있는 수
        int maxIdx = idx; // 인덱스
        // k개 탐색해서 가장 큰 수 고르기
        for(int j = idx; j <= k+i; j++){
            if(maxChar < number[j]){
                maxChar = number[j];
                maxIdx = j;
            }
        }
        answer += maxChar; // string에 그냥 char + 해서 넣을 수 있음
        idx = maxIdx + 1; // 고른 다음 부분부터 탐색
    }
    
    return answer;
}