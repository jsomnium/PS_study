#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// 소수 판별 함수
bool isPrime(int num){
    // 1과 2는 소수가 아님
    if(num < 2) return false;
    
    // 2부터 sqrt(num)까지 나누어 떨어지면 소수가 아님.
    // sqrt(num)은 num의 제곱근을 의미함.
    // 소수 판별 시 성능을 위해 2 ~ sqrt(num)까지만 검사함.
    for(int i = 2; i <= sqrt(num); i++)
        if(num % i == 0) return false;
    
    // 나누어 떨어지는게 없어야 소수
    return true;    
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v; // 수가 될 수 있는 정수들을 담는 배열
    vector<int> toNum; // 가능한 수 들을 담는 배열
    
    // 순열을 만들기 위해서 준비
    for(int i = 0; i < numbers.length(); i++) v.push_back(numbers[i]);
    sort(v.begin(), v.end());
    
    // 예시 (numbers = "17")
    // v = ['1', '7']
    // 첫 순열: '1', '17' → toNum = [1, 17]
    // 다음 순열: '7', '71' → toNum = [1, 17, 7, 71]
    // 결과적으로 1, 17, 7, 71이라는 숫자들이 만들어짐.
    do{
        string str = "";
        for(int i = 0; i < v.size(); i++){
            str.push_back(v[i]);
            toNum.push_back(stoi(str));
        }
    }while(next_permutation(v.begin(), v.end()));
    
    // 중복 제거
    sort(toNum.begin(), toNum.end());
    toNum.erase(unique(toNum.begin(), toNum.end()), toNum.end());
    
    // 만들어진 숫자들로 소수를 몇개 만들 수 있는지 카운트
    for(int i = 0; i < toNum.size(); i++)
        if(isPrime(toNum[i])) answer++;
    
    return answer;
}
