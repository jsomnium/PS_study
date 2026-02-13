#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    int final_result = 0;
    string temp = "";
    bool isMinus = false;

    for (int i = 0; i <= input.size(); i++) {
        // 문자열의 끝이거나 연산자를 만났을 때
        if (i == input.size() || input[i] == '+' || input[i] == '-') {
            
            if (isMinus) {
                final_result -= stoi(temp);
            } else {
                final_result += stoi(temp);
            }

            // 이번 기호가 '-'였다면 이제부터는 무조건 뺀다!
            if (input[i] == '-') {
                isMinus = true;
            }
            
            temp = ""; // 숫자 바구니 비우기
        } else {
            // 숫자일 때는 문자열에 추가
            temp += input[i];
        }
    }

    cout << final_result;
    return 0;
}