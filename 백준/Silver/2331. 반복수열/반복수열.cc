#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    // 입출력
    int START_NUMBER, MULTIPLE_COUNT;
    cin >> START_NUMBER >> MULTIPLE_COUNT;
    
    vector<int> v;
    set<int> s;
    
    // 중복된 수를 찾을 때 까지 반복한다
    int curNumber = START_NUMBER;
    while (s.count(curNumber) == 0){
        v.push_back(curNumber);
        s.insert(curNumber);
        
        int nextNumber = 0;
        int temp = curNumber;
        
        while (temp > 0){
            int digit = temp % 10;
            int multi = 1;
            for (int j = 0; j < MULTIPLE_COUNT; j++) multi *= digit;
            nextNumber += multi;
            temp /= 10;
        }
        curNumber = nextNumber;
    }
    
    // 중복된 수를 찾았다면, 반복 시작된 숫자 curNumber가 벡터의 몇 번째 인덱스인지 계산
    for (int i = 0; i < v.size(); i++){
        if (v[i] == curNumber){
            cout << i << endl;
            return 0;
        }
    }
}