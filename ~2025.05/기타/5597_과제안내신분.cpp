#include <iostream>
using namespace std;
 
int main() {
    int num;
    bool CheckList[31]={0,};
    for(int i = 1; i <= 28; i++){
        cin >> num; //제출한 학생의 출석번호 입력
        CheckList[num] = 1; //해당 출석번호에 해당하는 List의 값을 1로 만들어줌
    }
    for (int j = 1; j <= 30; j ++){
        if (CheckList[j] == 0) cout <<j<<"\n"; // 1이 아닌 값을 출력
    }
    return 0;
}