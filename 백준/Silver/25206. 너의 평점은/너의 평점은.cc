#include <iostream>
#include <string>

using namespace std;

int main() {
    // 빠른 입출력을 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string subject, grade;
    double credit;
    
    double sumCredit = 0.0;    // 학점 총합
    double sumScore = 0.0;     // (학점 * 과목평점) 총합

    for (int i = 0; i < 20; i++) {
        cin >> subject >> credit >> grade;

        if (grade == "P") continue; // P등급은 계산 제외

        sumCredit += credit;

        if (grade == "A+") sumScore += (credit * 4.5);
        else if (grade == "A0") sumScore += (credit * 4.0);
        else if (grade == "B+") sumScore += (credit * 3.5);
        else if (grade == "B0") sumScore += (credit * 3.0);
        else if (grade == "C+") sumScore += (credit * 2.5);
        else if (grade == "C0") sumScore += (credit * 2.0);
        else if (grade == "D+") sumScore += (credit * 1.5);
        else if (grade == "D0") sumScore += (credit * 1.0);
        else if (grade == "F") sumScore += (credit * 0.0);
    }

    cout << fixed;
    cout.precision(6);
    
    if (sumCredit == 0) cout << 0.000000 << "\n";
    else cout << sumScore / sumCredit << "\n";

    return 0;
}