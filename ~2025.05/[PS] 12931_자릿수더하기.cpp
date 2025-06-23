#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    while (n != 0){
      // 숫자 n을 10으로 계속 나눠서, 일의 자리 수만 남을 때까지 10으로 나눈 나머지를 더한다
        answer += n%10;
        n /= 10;
    }

    return answer;
}
