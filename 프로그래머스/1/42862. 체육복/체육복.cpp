#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n, 1);
    
    // 인덱스 보정 (학생 번호는 1부터 시작하므로 -1 해줌)
    for (auto l : lost){
        student[l-1]--; 
    }
    
    for (auto r : reserve){
        student[r-1]++;
    }
    
    // 빌려주기 로직
    for (int i = 0; i < n; i++){
        // 여벌이 있는 학생(2벌)만 빌려줄 수 있음
        if (student[i] == 2){
            // 앞 번호 학생에게 빌려주기
            if (i > 0 && student[i-1] == 0){
                student[i-1]++;
                student[i]--;
            } 
            // 뒷 번호 학생에게 빌려주기 (앞 사람에게 못 빌려줬을 때만 실행됨)
            else if (i < n - 1 && student[i+1] == 0){
                student[i+1]++;
                student[i]--;
            }
        }
    }
    
    for (auto s : student){
        if (s >= 1) answer++;
    }
    
    return answer;
}
