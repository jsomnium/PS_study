#include <iostream>
#include <math.h>
using namespace std;
void inputScore(double numOfStudent);

int main() {
    int C = 0; // 테스트 케이스의 개수
    int N = 0; // 각 테스트 케이스마다 학생의 수

    cin >> C; // 테스트 케이스의 개수 입력받기

    for (int i = 0; i < C; i++) {
        cin >> N;
        inputScore(N);
    }
}

void inputScore(double numOfStudent) {
    double tempScore[1000] = {};
    double sumOfScore = 0;
    double avg = 0;
    double numOfHighScoreStudent = 0;
    double percent = 0;

    for (int j = 0; j < numOfStudent; j++) {
        cin >> tempScore[j];
        sumOfScore += tempScore[j];
    }

    avg = sumOfScore / numOfStudent;

    for (int k = 0; k < numOfStudent; k++) {
        if (tempScore[k] > avg)
            numOfHighScoreStudent++;
    }

    percent = (numOfHighScoreStudent / numOfStudent) * 100;

    cout << fixed;
    cout.precision(3);
    cout << round(percent * 1000) / 1000 << "%" << endl;
}