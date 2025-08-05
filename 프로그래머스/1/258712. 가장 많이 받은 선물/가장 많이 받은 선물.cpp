#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    // 선물을 더 많이 준 사람 => 이 선물을 한개 받음
    // (두 사람의) 기록이 없거나 || 수가 같다면 => (선물지수가 큰 사람이) 1개 받음
    // (두 사람의) 선물지수도 같다면 => 선물 주고받지 않음
    
    // 선물지수 먼저 계산을 해야하는군?
    // 아니면 받은 선물, 준 선물을 배열로 먼저 계산하던가.
    // 선물을 가장 많이 받을 친구가 받을 선물의 수 구하기
    
    unordered_map<string, unordered_map<string, int>> giftLog;
    unordered_map<string, int> giftLevel;
    unordered_map<string, int> nextGift;
    
    // 주고받은 선물 기록하기
    for (auto gift : gifts){
        istringstream iss(gift);    // 공백 분리
        string giver, receiver;
        iss >> giver >> receiver;
        giftLog[giver][receiver]++;
    }
    
    // 선물지수 구하기
    for (auto& f : friends) {
        int give = 0, take = 0;

        for (auto& other : friends) {
            if (f == other) continue;
            give += giftLog[f][other];      // f가 준 선물
            take += giftLog[other][f];      // f가 받은 선물
        }
        giftLevel[f] = give - take;
    }
    
    for (int i = 0; i < friends.size(); ++i) {
        for (int j = i + 1; j < friends.size(); ++j) {
            string f = friends[i];
            string other = friends[j];

            int fGift = giftLog[f][other];
            int oGift = giftLog[other][f];

            if (fGift > oGift) {
                nextGift[f]++;
            } else if (fGift < oGift) {
                nextGift[other]++;
            } else {
                if (giftLevel[f] > giftLevel[other]) {
                    nextGift[f]++;
                } else if (giftLevel[f] < giftLevel[other]) {
                    nextGift[other]++;
                }
                // 같으면 아무도 안 받음
            }
        }
    }

    int answer = 0;
    for (auto& f : friends) {
        answer = max(answer, nextGift[f]);
    }
    
    return answer;
}