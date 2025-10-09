#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int totalHealth = health;
    
    // bandage [시전시간, 초당회복량, 추가회복량]
    // attacks [공격시간, 피해량]
    
    // 모든 공격이 끝난 직후 남은 체력 반환
    int curTime = 0;
    for (auto a : attacks){
        int attackTime = a[0];
        int attackDamage = a[1];
        cout << curTime << " / attackTime: " << attackTime << endl;
        cout << curTime << " / attackDamage: " << attackDamage << endl;
        
        if (curTime == 0){
            // 처음 시작 상태에서는 최대 체력이므로
            // 첫 공격까지 체력 상태가 그대로임
            curTime = attackTime + 1;
            totalHealth-= attackDamage;
            cout << "다음 " << curTime << "에서의 체력 / totalHealth: " << totalHealth << endl;
            continue;
        } 
        
        // attackTime 전까지 체력 회복
        int timeCnt = attackTime - curTime; // 다음 공격 전까지 회복하는 시간
        int bonusHealthCnt = timeCnt / bandage[0]; // 보너스 회복 횟수
        totalHealth += timeCnt * bandage[1] + bonusHealthCnt * bandage[2];
        
        // 최대 체력 초과 불가능
        if (totalHealth > health) totalHealth = health;
        cout << "체력 회복 / totalHealth: " << totalHealth << endl;
        
        // attackTime에 공격
        totalHealth -= attackDamage;
        cout << "공격 받음 / totalHealth: " << totalHealth << endl;
        curTime = attackTime + 1;
        
        if (totalHealth <= 0) return -1;        
    }
    return totalHealth;
}