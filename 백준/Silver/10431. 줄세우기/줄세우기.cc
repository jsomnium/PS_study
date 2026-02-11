#include <vector>
#include <set>
#include <iostream>

using namespace std;

int main(){
    int P; // 테스트 케이스의 수
    cin >> P;
    
    while (P--){
        int testCase = 0;
        int totalSteps = 0;
        vector<int> Student(20, 0);
        set<int> Sort;
    
        // 테스트케이스 입력받기
        cin >> testCase;
        for (int i = 0; i < 20; i++){
            cin >> Student[i];
        }
    
        // i번째 학생을 줄세우려고 할 때,
        // 자신보다 키가 큰 학생이 있으면 줄을 다시 세워야 한다.
        // 즉, 자신보다 키가 큰 학생이 처음 나오는 위치를 확인하면 된다.
        for (int i = 0; i < 20; i++) {
            int curStudent = Student[i];

            // lower_bound로 나보다 키가 크거나 같은 첫 번째 사람 찾기
            auto it = Sort.lower_bound(curStudent);

            // it부터 끝(end)까지의 거리가 바로 '나보다 키 큰 사람의 수'
            // 즉, 한 발씩 물러나야 하는 학생들의 수입니다.
            totalSteps += distance(it, Sort.end());

            // 이제 줄에 서기
            Sort.insert(curStudent);
        }
    
        cout << testCase << " " << totalSteps << endl;
    }
    
    return 0;
}